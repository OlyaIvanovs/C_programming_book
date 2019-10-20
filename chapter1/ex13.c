#include <stdio.h>

#define OUT 0
#define IN 1
#define NUMW 5

/* Print a histogram of the lengths of words */

main()
{
    int c, lw, i, k, m, state;
    int lengths[NUMW];

    i = lw = k = 0;

    for (i = 0; i < NUMW; ++i)
        lengths[i] = 0;

    while ((c = getchar()) != EOF) {
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

    for (i = 0; i < NUMW; ++i) {
        printf("%d ", i+1);   
        for (m = 0; m < lengths[i]; ++m) {
            printf("_");
        }
        printf("\n");   
    }
}