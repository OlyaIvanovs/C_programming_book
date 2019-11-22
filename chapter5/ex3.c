#include <stdio.h>
#define MAXLINE 100

void strcat1(char *, char *);

int main() 
{
    char s[MAXLINE] = "mama";
    char t[MAXLINE] = " myla ramy";
    strcat1(s, t);
    printf("%s", s);
    return 0;
}


/* stcat: concatenate t to end of s; s must be big enough */
void strcat1(char *s, char *t)
{
    while (*s++ != '\0')
        ;
    --s;
    while ((*s++ = *t++) != '\0')
        ;
}