#include <stdio.h>
#define MAXLEN 100

void itoa(int n, char s[]);

int main()
{
    char s[MAXLEN];
    int n;
    
    n = -123;
    itoa(n, s);
    printf("%s", s);

    return 0;
}

void itoa(int n, char s[])
{
    int sign;

    static int i = 0;

    if ((sign = n) < 0) {
        s[i++] = '-';
        n = -n;
    }
        
    if (n / 10)
        itoa(n / 10, s);
    s[i++] =  n % 10 + '0';

    s[i] = '\0';
}