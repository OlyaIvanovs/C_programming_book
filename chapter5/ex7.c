#include <stdio.h>
#include <string.h>

#define MAXLINES 1000
#define MAXLEN 1000 /* max length of any input line */
#define MAXTEXT 100000

char *lineptr[MAXLINES]; /* pointers to text lines */
char lines[MAXTEXT]; /* to store lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int mgetline(char *, int);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        // printf("lineptr 0 %s", lineptr[0]);
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
    char line[MAXLEN];
    char *current = &lines[0];

    nlines = 0;
    while ((len = mgetline(line, MAXLEN)) > 0) {
        // if (nlines >= maxlines || (p = alloc(len)) == NULL)
        if (nlines >= maxlines || (lines - &lines[0]+ len) > MAXTEXT)
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

/* write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s", *lineptr++);
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

int mgetline(char *s, int lim)
{
    int c, i;
    char *t = s;

    while (lim-- > 0 && (c=getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';

    return s-t;
}