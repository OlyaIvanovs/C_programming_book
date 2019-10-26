#include <stdio.h>
#define MAXLINE 100
#define TAB 8

/* Replaces strings of blanks by the minimum numbers tabs and blanks to achieve the same spacing */

int getline(char line[], int maxline);
void entab(char line[], int len);
int check_string_is_blank(char line[], int len);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
        if (check_string_is_blank(line, len) == 1) {
            entab(line, len);
            printf("%s ", line);
        }
    return 0;
}

int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    } 
    s[i] = '\0';
    return i;
}

int check_string_is_blank(char line[], int len)
{
    for (int i = 0; i < len-1; ++i) {
        if ((line[i] !=  ' ') & (line[i] !=  '\t')) {
            return 0;
        }
    }
    return 1;
}

void entab(char line[], int len) 
{
    int a = len-1;
    for (int i = 0; i <= a; ++i) {
        if ((line[i] ==  '\t')) 
            len += TAB - 1;
    }


    int tabs = len / TAB;
    int blanks = len - tabs * TAB;
    int i = 0;

    for (blanks = blanks; blanks > 0; --blanks) {
        line[i] = ' ';
        ++i;
    }

    for (tabs = tabs; tabs > 0; --tabs) {
        line[i] = '\t';
        ++i;
    }

    line[i] = '\0';
}