#include <stdio.h>
#define MAXLINE 1000

/* Convert n to characters in s. The third argument is a minimum field width; the converted number must be padded with blanks on the left */


void itoa(int n, char s[], int field);
void reverse(char s[], int field);

int main() 
{
    int n, field;
    char s[MAXLINE];
    
    n =  34534534;
    field = 5;
    itoa(n, s, field);
}


void itoa(int n, char s[], int field)
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;

    i = 0;

    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s, field);
    printf("%s", s);
}


void reverse(char s[], int field)
{
    int len, j;
    char s1[MAXLINE];

    for (len = 0; s[len] != '\0'; len++){}

    for (j = 0; j <= len - 1; j++) {
        s1[j] = s[len-j-1];
    }

    if (field > len) {
        for (int i = 0; i < (field - len); i++) {
            s[i] = ' ';
        }

        int i;
        for (i = (field - len), j = 0; i <= field; i++, j++) {
            s[i] = s1[j];
        }

        s[i] = '\0';
    } else {
        int i;
        for (i = 0; i < len; i++) {
            s[i] = s1[i];
        }
        s[i] = '\0';
    }
}   