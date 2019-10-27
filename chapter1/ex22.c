#include <stdio.h>
#define MAXLINE 100
#define LINESIZE 10
#define TAB 8

/* Folds long input into two or more schorter lines */

int getline(char line[], int maxline);
void foldline(char line[], int linesize, int len);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > LINESIZE) {
            foldline(line, LINESIZE, len);
        }
        printf("\n%s", line);
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

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}


void foldline(char line[], int linesize, int len)
{
    int k = 0;
    
    for (int i = linesize; i >= 0; --i) {
        if (i == 0) {
            for (int j = len; j >= linesize + k - 1; --j) {
                line[j+2] = line[j];
            } 
            line[linesize + k - 1] = '-';
            line[linesize + k] = '\n';
            k += linesize + 2;
            i = linesize;
        } else {

            if ((line[i + k] == ' ') || (line[i + k + 1] == '\0')) {
                line[i + k] = '\n';

                k += i + 1;

                if (i != linesize) {
                    k += 1;
                }

                if (line[i + k] != '\0') {
                    i = linesize;
                } else {
                    i = -1;
                }
            }
        }
    }  
}



