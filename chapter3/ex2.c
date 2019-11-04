#include <stdio.h>
#define MAX 100000

/* Converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s */
void escape(char s[], char t[]);

int main()
{
    char s[MAX] = "Converts characters  like newline and tab into visible escape";
    char t[MAX] = "";

    escape(s, t);
    printf("%s", t);
}


void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++, j++)
        switch (s[i]) {
            case ' ': 
                t[j++] = '\\';
                t[j] = 'b';
                break;
            case '\t': 
                t[j++] = '\\';
                t[j] = 't';
                break;
            case '\n': 
                t[j++] = '\\';
                t[j] = 'n';
                break;        
            default:
                t[j] = s[i];
        }

    t[j] = '\0';
}