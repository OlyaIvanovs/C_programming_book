
#include <stdio.h>

#define MAXLINE 1000000

int is_notation(char a, char b);
void expand(char s1[], char s2[]);
int fill(char s[], char a, char b, int j);

int main(){
    char s2[MAXLINE];
    // char string1[MAXLINE] = "b-w";
    // char string2[MAXLINE] = "2-5-9";
    // char string3[MAXLINE] = "a-b-c-f";
    char string4[MAXLINE] = "-a-b-c9-0-3b-s-";  
    // char string5[MAXLINE] = "a-0-6b--pq-w9-0-3";  // a-0123456b--pqrstuvw9-0123
    // char string6[MAXLINE] = "-a-z 0-9 a-d-f -0-2 some text 1-1 WITH CAPITALS! 0-0 5-3 -"; // -abcdefghijklmnopqrstuvwxyz 0123456789 abcdef -012 some text 1-1 WITH CAPITALS! 0-0 5-3 -
    // char string7[MAXLINE] = "5-w"; // 5-w
    expand(string4, s2);
    printf("%s", s2);
}

int is_notation(char a, char b) {
    if (((a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z') \
        || (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z') \
        || (a >= '0' && a <= '9' && b >= '0' && b <= '9')) & (a < b)) {
        return 1;
    } else {
        return 0;
    }
}

int fill(char s[], char a, char b, int j)
{
    if (s[j-1] == a) {
        s[j] = a + 1;
    } else {
        s[j] = a;
    }

    for (int f = s[j]; f <= b; j++, f++) {   // fill string 
        s[j] = f;
    }
    return j;
}


void expand(char s1[], char s2[])
{
    int j = 0;
    for (int i = 0; s1[i] != '\0'; i++) {        
        if (s1[i] == '-') {
            if (is_notation(s1[i - 1], s1[i + 1])) {
                j = fill(s2, s1[i - 1], s1[i + 1], j);
                ++i;
            } else {
                s2[j++] = s1[i];  // copy
            }
        } else if (s1[i + 1] !=  '-' || s1[i - 1] != '-') {   // other symbols
            s2[j++] = s1[i];
        }
    }
}