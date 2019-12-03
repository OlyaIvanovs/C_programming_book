#include <stdio.h>
#define MAXLINE 100

void mystrncat(char *, char *, int n);

int main() 
{
    char s[MAXLINE] = "myla ramy toto mama";
    char t[MAXLINE] = "tot";
    int num = 5;

    mystrncat(s, t, num);
    printf("%s", s);

    return 0;
}


/* concatenate n characters of string t to string s */
void mystrncat(char *s, char *t, int n)
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