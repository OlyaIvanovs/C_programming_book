#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 100
#define MAXWORD 100
#define MAXWORDS 100
#define MAXLINES 100

struct tnode *addtree(struct tnode *, char *, int);
struct countnode *treecount(struct tnode *, struct countnode *c);
struct countnode *addcounttree(struct tnode *, struct countnode *);

struct tnode *talloc(void);
struct countnode *countalloc(void);

void treeprint(struct tnode *);
void counttreeprint(struct countnode *);

char *mystrdup(char *);
int getword(char *, int);

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

struct tnode {              
    char *word;  /* pointer to the word */
    int count;  /* number of lines where word occurences */            
    struct tnode *left;     /* left child */
    struct tnode *right;    /* right child */
};

struct countnode {              
    char *words[MAXWORDS];  /* array of pointers to the word */
    int num; /* the number of word in array */
    int count;  /* number of lines where word occurences */            
    struct countnode *left;     /* left child */
    struct countnode *right;    /* right child */
};

/* word frequency count */
int main(int argc, char **argv) 
{
    struct tnode *root;
    struct countnode *countroot;
    char word[MAXWORD];
    int line = 0;

    root = NULL;
    countroot = NULL;
    
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) 
            root = addtree(root, word, line);
    }
    countroot = treecount(root, countroot);
    printf("In alphabetical order: \n");
    treeprint(root);
    printf("In order of frequency of occurence: \n");
    counttreeprint(countroot);
    return 0;
}
 
struct tnode *addtree(struct tnode *p, char *w, int n)
{
    int cond;

    if (p == NULL) {
        p = talloc();   /* make a new node */
        p->word = mystrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;
    }
    else if (cond < 0) /* less than into left subtree */
        p->left = addtree(p->left, w, n);
    else            /* greater than into right subtree */
        p->right = addtree(p->right, w,n);
    return p;
}

struct countnode *addcounttree(struct tnode *p, struct countnode *c)
{
    int cond;

    if (c == NULL) {
        c = countalloc();   /* make a new node */
        c->count = p->count;
        c->left = c->right = NULL;
        c->words[0] = mystrdup(p->word);
        c->num = 1;
        int a = p->count - c->count;
    } else if ((cond = (p->count - c->count)) == 0 ) {
        c->words[c->num] = mystrdup(p->word);
        c->num++;
    }
    else if (cond < 0) /* less than into left subtree */
        c->left = addcounttree(p, c->left);
    else            /* greater than into right subtree */
        c->right = addcounttree(p, c->right);
    return c;
}

struct countnode *treecount(struct tnode *p, struct countnode *c)
{
    if (p != NULL) {
        c = treecount(p->left, c);
        c = addcounttree(p, c);
        c = treecount(p->right, c);
    }
    return c;
}

void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

void counttreeprint(struct countnode *c)
{
    if (c != NULL) {
        counttreeprint(c->left);
        for (int num = 0; num < c->num; num++) {
            printf("%4d %s ", c->count, c->words[num]);
        }
        printf("\n");
        counttreeprint(c->right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/* countalloc: make a countnode */
struct countnode *countalloc(void)
{
    return (struct countnode *) malloc(sizeof(struct countnode));
}


char *mystrdup(char *s) /* make a duplicate of s */
{
    char *p;

    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
} 

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch())) {
        if (c == '\n') { /* new line */
            *w = '\n';
            return c;
        }
    }  
    
    if (c != EOF)
        *w++ = c;
    
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }

    *w = '\0';
    return word[0];
}