#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define SIZE 10

int getch(void);
void ungetch(int);
int getint(int *pn);
char buf[BUFSIZE];
int bufp = 0;
int sp = 0;

int main() 
{
    int n, array[SIZE], getint(int *pn);
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++);

    for (n = 0; n < SIZE; n++) {
        printf("%d ", array[n]);
    }

    return 0;
}


/* getint: get next integer from input *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar(); 
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE) 
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}