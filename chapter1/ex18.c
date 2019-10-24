#include <stdio.h>
#define MAXLINE 100
#define MAXINPUT 1000
#define PRINT_FROM 10

int getline(char line[], int maxline);
int to_print(char to[], char from[], int len);

/* print all input lines that are longer than 80 charachters */

int main()
{
    int len;
    char line[MAXLINE];
    char lines_to_print[MAXINPUT];
    int len_to_print;

    len_to_print = 0;

    while ((len = getline(line, MAXLINE)) > 0) {
        len_to_print = to_print(lines_to_print, line, len_to_print);
    }
        

    printf("All lines without trailing blanks, tabs and blank lines: \n%s", lines_to_print);
    return 0;
}

int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    } 
    s[i] = '\0';
    return i;
}

int to_print(char to[], char from[], int len)
{
    int i, j;

    i = j = 0;

    /* remove blanks from the beginning the line */
    while ((from[i] == ' ') || (from[i] == '\t'))
        ++i;

    while ((to[len+j] = from[i]) != '\0') {
        ++i;
        ++j;
    }

    /* to[lem*j-1] = '\n' */
    /* remove blanks from the end of the line */
    while ((to[len+j-2] == ' ') || (to[len+j-2] == '\t')) {
        --j;
    }

    return len+j;
}   