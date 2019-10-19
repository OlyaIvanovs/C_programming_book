#include <stdio.h>

/* Copy input to output, replacing more blanks by a single blank */

main() 
{
    int c, bl;
    bl = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (bl == 0) 
                putchar(c);
            ++bl;
        }
        else {
            bl = 0;
            putchar(c);
        }
    } 
}