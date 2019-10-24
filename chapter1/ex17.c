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

    while ((len = getline(line, MAXLINE)) > 0)
        if (len > PRINT_FROM ) {
            len_to_print = to_print(lines_to_print, line, len_to_print);
        }

    printf("All lines that are longer than 10 charachters: \n%s",lines_to_print);
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
    int i;

    i = 0;
    while ((to[len+i] = from[i]) != '\0')
        ++i;
    
    return len+i;
}