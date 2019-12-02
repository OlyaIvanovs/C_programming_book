#include <stdio.h>
#define MAXLINE 100

void mystrncpy(char *, char *, int n);

int main() 
{
    char s[MAXLINE] = "myla ramy toto mama";
    char t[MAXLINE] = "tototo";
    int num = 10;

    if (num > 0)
        mystrncpy(s, t, num);
    printf("%s", s);

    return 0;
}


/* copies at most n characters of t to s */
void mystrncpy(char *s, char *t, int n)
{   
    while (n > 0) {
        if (*t != '\0')
        *s++ = *t++;
        n--;
    }
    while (*s++ != '\0')
        ;
    *s++ = '\0';
}