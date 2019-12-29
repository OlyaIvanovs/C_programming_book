#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000 /* max lines to be sorted */
#define MAXLEN 1000 /* max length of any input line */
#define MAXTEXT 100000
char *lineptr[MAXLINES]; /* pointers to text lines */
char lines[MAXTEXT]; /* to store lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void mqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
void reverseqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int mstrcmp(char *, char *);
int fmstrcmp(char *, char *);
int mgetline(char *line, int lim);

int main(int argc, char *argv[]){
    int nlines; /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */
    int reverse = 0; /* 1 if decreasing order */
    int foldcase = 0; /* 1 if fold upper and lower case together */ 

    while (--argc > 0) {
        if ((*++argv)[0] == '-' && (*argv)[1] == 'n') {
            numeric = 1;
        } else if ((*argv)[1] == 'r') {
            reverse = 1;
        } else if ((*argv)[1] == 'f') {
            foldcase = 1;
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        if (reverse == 1) {
            reverseqsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))(numeric ? numcmp : (foldcase ? fmstrcmp : mstrcmp)));
        } else {
            mqsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))(numeric ? numcmp : (foldcase ? fmstrcmp : mstrcmp)));
        }
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }

    return 0;
}

void writelines(char *lineptr[], int nlines){
    while (nlines-- > 0){
        printf("%s", *lineptr++);
    }
}


int readlines(char *lineptr[], int maxlines){
    int len;
    char line[MAXLEN];
    char *current = &lines[0];
    int nlines = 0;

    while ((len = mgetline(line, MAXLEN)) > 0) {
        if (nlines > maxlines || (lines - current + len) > MAXTEXT) 
            return -1;
        else {
            lineptr[nlines++] = current;
            strncpy(current, line, len);
            current += len;
            *current = '\0';
            current++;
        }
    }

    return nlines;
}

int mgetline(char *line, int lim){
    int c, i;
    char *linestart = line;

    while (lim-- > 0 && (c = getchar()) != EOF && c != '\n') 
        *line++ = c;
    if (c == '\n')
        *line++ = c;
    *line = '\0';

    return line - linestart;
}

/* sort v[left]...v[right] into increasing order */
void mqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) /* do nothing if array contains fewer than two elements */
        return;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    mqsort(v, left, last-1, comp);
    mqsort(v, last+1, right, comp);
}


/* sort v[left]...v[right] into decreasing order */
void reverseqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) /* do nothing if array contains fewer than two elements */
        return;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) > 0)
            swap(v, ++last, i);
    swap(v, left, last);
    reverseqsort(v, left, last-1, comp);
    reverseqsort(v, last+1, right, comp);
}



void swap(void *v[], int i, int j){
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* compare s1 and s2 numerically */
int numcmp(char *s1, char *s2){
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else 
        return 0;
}

/* case ditinctions are not made during sorting */
int fmstrcmp(char *s, char *t) {
    int i;

    for (i = 0; tolower(s[i]) == tolower(t[i]); i++)
        if (*s == '\0')
            return 0;
    return tolower(*s) - tolower(*t);
}


int mstrcmp(char *s, char *t) {
    int i;
    
    for (i = 0; s[i] == t[i]; i++) 
        if (*s == '\0')
            return 0;
    return *s - *t;
}