#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 100
#define TAB 4

/* Replace tabs in input with the proper number of blanks to space to the next tab stop */
/* entab -m +n, to mean tab stops every n columns, starting at column m */

int mygetline(char line[], int, int);

int main(int argc, char *argv[])
{
    int len, c;
    char line[MAXLINE];
    int tab = TAB;
    int n = 0;

    while (--argc > 0) {
        if ((*++argv)[0] == '-') {
            tab = atoi(++(*argv));
        } else if ((*argv)[0] == '+') {
            n = atoi(*argv);
        }
    }

    while ((len = mygetline(line, MAXLINE, tab)) > 0)
        printf("\n%s ", line);
    return 0;
}

int mygetline(char s[], int lim, int tab)
{
    int c, i;
    int blanks_to_tab;

    for (i = 0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i) {
        if (c == '\t') {
            blanks_to_tab = tab - (i % tab);
            while (blanks_to_tab > 0) {
                s[i] = '_';  
                if (blanks_to_tab > 1)
                    ++i;
                --blanks_to_tab;  
            }
        } else {
            s[i] = c;
        }
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    } 
    s[i] = '\0';
    return i;
}