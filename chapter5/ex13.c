#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXTEXT 100000
#define MAXLEN 1000 /* max length of any input line */

char *lineptr[MAXLINES];
char lines[MAXTEXT]; /* to store lines */

int mgetline(char *, int);
int readlines(char *lineptr[], int  );
void writelines(char *lineptr[], int , int);

int main(int argc, char *argv[]) {
    int linestoprint = 0;
    int nlines = readlines(lineptr, MAXLINES);

    while (--argc > 0) {
        if ((*++argv)[0] == '-') {
            linestoprint = atoi(++(*argv));
        }
    }

    if (linestoprint > nlines) 
        linestoprint = nlines;

    printf("linestoprint%d\n", linestoprint);

    writelines(lineptr, nlines, linestoprint);
}

int readlines(char *lineptr[], int maxlines){
    int len;
    char line[MAXLEN];
    char *current = &lines[0];
    int nlines = 0;

    while ((len = mgetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (lines - &lines[0] + len) > MAXTEXT) {
            return -1;
        } else {
            lineptr[nlines++] = current;
            strncpy(current, line, len);
            current += len;
            *current = '\0';
            current++;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines, int linestoprint) {
    lineptr = &lineptr[nlines-1];
    while (linestoprint-- > 0) {
        printf("%s", *lineptr--);
    }
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