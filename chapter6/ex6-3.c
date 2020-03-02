#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 100
#define MAXWORD 100
#define MAXLINES 100

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
struct tnode *talloc(void);
char *mystrdup(char *);
int getword(char *, int);

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

struct tnode {              
    char *word;  /* pointer to the word */
    int count;  /* number of lines where word occurences */
    int lines[MAXLINES];              
    struct tnode *left;     /* left child */
    struct tnode *right;    /* right child */
};

/* word frequency count */
int main(int argc, char **argv) 
{
    struct tnode *root;
    char word[MAXWORD];
    int line = 0;

    root = NULL;
    
    while (getword(word, MAXWORD) != EOF) {
        if (word[0] == '\n')
            line += 1;
        if (isalpha(word[0])) 
            root = addtree(root, word, line);
    }
    treeprint(root);
    return 0;
}
 
struct tnode *addtree(struct tnode *p, char *w, int n)
{
    int cond;

    if (p == NULL) {
        if (strcmp(w, "and") == 0) 
            return p;
        p = talloc();   /* make a new node */
        p->word = mystrdup(w);
        p->lines[0] = n;
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        int num = p->count;
        if (p->lines[num - 1] != n) {
            p->lines[num] = n;
            p->count += 1;
        }
    }
    else if (cond < 0) /* less than into left subtree */
        p->left = addtree(p->left, w, n);
    else            /* greater than into right subtree */
        p->right = addtree(p->right, w,n);
    return p;
}

void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%s: ", p->word);
        for (int i = 0; i < p->count; i++) {
            printf("%d, ", p->lines[i]);
        }
        printf("\n");
        treeprint(p->right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
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