#include <stdio.h>
#define MAXLINE 1000

/* Converts the integer n into a base b character representation in the string s */

void itob(int n, char s[], int b); 
void reverse(char s[]);
char itoc(int i);


int main()
{
    int n, b;
    char s[MAXLINE];
    
    n = 345;
    b = 2;
    itob(n, s, b);
    printf("%d into a base %d is %s\n", n, b, s);

    n = 1023;
    b = 8;
    itob(n, s, b);
    printf("%d into a base %d is %s\n", n, b, s);
}

char itoc(int i) {
  if (i < 10) {
    return i + '0';
  } else {
    return (i - 10) + 'a';
  }
}

void itob(int n, char s[], int b){

    int i = 0;
    int sign;

    if ((sign = n) < 0)
        n = -n;

    do {
        s[i++] = itoc(n % b);
    } while ((n /= b) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i++] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int len, j;
    char s1;

    for (len = 0; s[len] != '\0'; len++){}

    for (j = 0; j <= len/2; j++) {
        s1 = s[j];
        s[j]  = s[len-j-1];
        s[len-j-1] = s1;
    }
}