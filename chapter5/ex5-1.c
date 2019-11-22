#include <stdio.h>
#define MAXLINE 100

void mystrncpy(char *, char *, int n);

int main() 
{
    char s[MAXLINE] = "myla ramy toto mama";
    char t[MAXLINE] = "toto mma";
    int num = 3;

    mystrncpy(s, t, num);
    printf("%s", s);

    return 0;
}


/* copies at most n characters of t to s */
void mystrncpy(char *s, char *t, int n)
{   
    while (*s++ != '\0')
        ;
    s--;
    if (n <= 0) return;

    while ((*s++ = *t++) != '\0') {
        n--;
        if (n == 0)
            return;
    }
}