#include <stdio.h>
#define SWAP(a, b)  { \
                        int temp = a; \
                        a = b;      \
                        b = temp;      \
                    } 

/* Defines a macro that interchanges two arguments */

int main()
{
    int x = 10;
    int y = 20;
    printf("x %d, y %d", x, y);
    SWAP(x, y);
    printf("After interchanging: x %d, y %d", x, y);
}