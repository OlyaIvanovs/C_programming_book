#include <stdio.h>

#define OUT 0
#define IN 1
#define NUMW 100

/* Print a histogram of the lengths of words */

int main()
{
    int c, lw, i, k, m, state, max, t;
    int lengths[NUMW];

    i = lw = k = 0;

    for (i = 0; i < NUMW; ++i)
        lengths[i] = 0;

    while ((c = getchar()) != EOF && k <= 100) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                lengths[k] = lw; 
                lw = 0;
                ++k;
            }
            state = OUT;
        } else {            
            state = IN;
            ++lw;
        }

    }

    for (i=0; i < k; ++i) {
        printf("%d ", i + 1);   
        for (m = 0; m < lengths[i]; ++m) {
            printf("_");
        }
        printf("\n");   
    }

    max = lengths[0];
    for (i=1; i < k; ++i) {
         if (lengths[i] > max)
            max = lengths[i];
    }

    printf("Vertikal\n");
    for (t=max; t > 0; --t) {
        for (i=0; i < k; ++i) {
            if (lengths[i] < t) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}