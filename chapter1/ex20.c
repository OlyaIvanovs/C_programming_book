#include <stdio.h>
#define MAXLINE 100
#define TAB 4

/* Replace tabs in input with the proper number of blanks to space to the next tab stop */

int getline(char line[], int maxline);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
        printf("\n%s ", line);
    return 0;
}

int getline(char s[], int lim)
{
    int c, i;
    int blanks_to_tab;

    for (i = 0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i) {
        if (c == '\t') {
            blanks_to_tab = TAB - (i % TAB);
            while (blanks_to_tab > 0) {
                s[i] = ' ';  
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