#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 100
#define MAXWORD 100
#define MAXWORDS 100

struct tnode *addtree(struct tnode *, char *, int);
struct wnode *addsubtree(struct wnode *, char *);
void treeprint(struct tnode *);
void subtreeprint(struct wnode *);
struct tnode *talloc(void);
struct wnode *walloc(void);
char *mystrdup(char *, int);
char *mystrdup2(char *);
int getword(char *, int);

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

struct tnode {              /* the tree node */
    char *root_word;  /* pointer to the root word of the node*/
    struct wnode *words[MAXWORDS];  /* array ofpointers to the words of the node */
    int count;              /* number of occurences */
    struct tnode *left;     /* left child */
    struct tnode *right;    /* right child */
};

struct wnode {              /* the subtree node grouped by root */
    char *word;  /* pointers to the word*/
    int count;              /* number of occurences */
    struct wnode *left;     /* left child */
    struct wnode *right;    /* right child */
};

/* word frequency count */
int main(int argc, char **argv) 
{
    struct tnode *root;
    char word[MAXWORD];
    int root_size;

    if (argc == 3) {
        if (strcmp("-n", argv[1]) == 0)
            root_size = atoi(argv[2]);
        } else {
            root_size = 2;
    }         

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word, root_size);
    treeprint(root);
    return 0;
}
 
struct tnode *addtree(struct tnode *p, char *w, int n)
{
    int cond, k;
    if (p == NULL) {
        p = talloc();   /* make a new node */
        p->root_word = mystrdup(w, n);
        p->count = 1;
        p->left = p->right = NULL;
        p->words[0] = addsubtree(NULL, w);
    } else if ((cond = strncmp(w, p->root_word, n)) == 0) {
        k = p->count;
        p->words[k] = addsubtree(p->words[0], w);
        p->count++;
    }
    else if (cond < 0) /* less than into left subtree */
        p->left = addtree(p->left, w, n);
    else            /* greater than into right subtree */
        p->right = addtree(p->right, w, n);
    return p;
}

struct wnode *addsubtree(struct wnode *p, char *w)
{
    int cond, k;
    if (p == NULL) {
        p = walloc();   /* make a new node */
        p->word = mystrdup2(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        k = p->count;
        p->count++;
    }
    else if (cond < 0) /* less than into left subtree */
        p->left = addsubtree(p->left, w);
    else            /* greater than into right subtree */
        p->right = addsubtree(p->right, w);
    return p;
}

void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("\nGroup with RootWord: %s %4d\n", p->root_word, p->count);
        subtreeprint(p->words[0]);
        treeprint(p->right);
    }
}

void subtreeprint(struct wnode *p)
{
    if (p != NULL) {
        subtreeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        subtreeprint(p->right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/* walloc: make a word node */
struct wnode *walloc(void)
{
    return (struct wnode *) malloc(sizeof(struct wnode));
}

char *mystrdup(char *s, int n) /* make a duplicate of s */
{
    char *p;

    p = (char *) malloc(n + 1);
    if (p != NULL)
        strncpy(p, s, n);
    return p;
}

char *mystrdup2(char *s) /* make a duplicate of s */
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
    int c, b, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;

    if (c != EOF)
        *w++ = c;
    
    if (!isalpha(c)) {
        if (c == '\"') { /* string constant */
            for (c = getch(); c != '\"'; c = getch())
                ;
        } else if (c == '#') { /* preprocessor */
            for (c = getch(); c != '\n'; c = getch())
                ;
        } else if (c == '/') {/* comment */
            if ((c = getch()) == '/') /* single comments */
                for (c = getch(); c != '\n'; c = getch())
                    ;
            else if (c == '*') /* multiline comment */
                for (c = getch(), b = getch(); c != '*' && b != '/'; c = getch(), b = getch())
                    ungetch(b);
            else ungetch(c);
        } else {

        }

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