#include <stdio.h>
#define MAXLINE 100

int getline(char line[], int maxline);
void reverse(char to[], char from[], int len);

/* reverse its input a line at a time */

int main()
{
    int len;
    char line[MAXLINE];
    char reverse_line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        reverse(reverse_line, line, len);
        printf("Reverse line: %s\n", reverse_line);
    }       
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

void reverse(char to[], char from[], int len)
{
    int i;

    i = 0;

    while ((len - 2 - i) >= 0) {
        to[i] = from[len - 2 - i];
        ++i;
    }

    to[i] = '\0';
}   