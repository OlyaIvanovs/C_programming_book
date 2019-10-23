#include <stdio.h>
#define MAXLINE 10

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    
    if (max > 0) {
        printf("Longest input has %d characters\n", max);
        printf("%s", longest);
    }
    return 0;
}

int getline(char s[], int lim)
{
    int c, i, more_max;
    more_max = 0;

    for (i = 0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    } else if (c != EOF) {
        ++more_max;
        while ((c = getchar()) != EOF && c!='\n') {
            ++more_max;
        }
    }
    s[i] = '\0';
    return i+more_max;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}