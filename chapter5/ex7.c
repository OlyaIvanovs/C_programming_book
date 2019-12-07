#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000 /* max length of any input line */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int getline(char *, int);
char *alloc(int);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    int nlines;

    if (nlines == readlines(lineptr, MAXLINES) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
    return 0;
}

/* read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right) return; /* do nothing if array contains fewer than 2 elements */

    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i<= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int getline(char *s, int lim)
{
    int c, i;

    // for (i = 0; i < lim -1 && (c=getchar()) != EOF && c != '\n'; ++i)
    //     *s++ = c;
    // if (c == '\n')
    //     *s++ = c;
    // *s = '\n';

    return i;
}