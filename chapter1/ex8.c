#include <stdio.h>

/* Count blanks, tabs and newlines */

main() 
{
    int c, bl, tb, nl;

    bl = tb = nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++tb;
        if (c == ' ')
            ++bl;
    }
    printf("blanks: %d    tabs: %d   newlines: %d", bl, tb, nl);
}