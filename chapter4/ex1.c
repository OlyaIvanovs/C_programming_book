#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[], int len);
void reverse(char s[]);

char pattern[] = "ould";

int main()
{
    char line[MAXLINE];

    reverse(pattern);
    int len;
    while ((len = getline(line, MAXLINE))> 0) {
        int occurence = strindex(line, pattern, len);
        if (occurence >= 0) {
            printf("The rightmost occurence of t in string %d", occurence);
        } else {
            printf("There is no occurence");
        }
    }
    return 1;
}

int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF &&  c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* returns the position of the rightmost occurence */
int strindex(char s[], char t[], int len)
{
    int i, j, k;
    for (i = len - 2; i >= 0; i--) {
        for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j--, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return j;
    }
    return -1;
}

void reverse(char s[])
{
    int len, j;
    char s1;

    for (len = 0; s[len] != '\0'; len++){}

    for (j = 0; j < len/2; j++) {
        s1 = s[j];
        s[j]  = s[len-j-1];
        s[len-j-1] = s1;
    }
}