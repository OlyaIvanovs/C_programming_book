#include <stdio.h>
#define MAXLINE 100

int strend(char *, char *);

int main() 
{
    char s[MAXLINE] = "myla ramy toto mama";
    char t[MAXLINE] = "toto mma";
    printf("%d", strend(s, t));

    return 0;
}


/* returns 1 if the string t occurs at the end of the string s, and 0 otherwise */
int strend(char *s, char *t)
{
    int n = 0;
    
    while (*s++ != '\0')
        ;
    while (*t++ != '\0') {
        n++;
    }

    while (*s-- == *t--) {
        if (n == 0)
            return 1;
        n--;
    }
    return 0;
}