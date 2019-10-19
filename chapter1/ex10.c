#include <stdio.h>

/* Copy input to output, replacing tab by \t, backspace by \b and backslasch by\\ */

main()
{
    int c;
    
    while ((c = getchar()) != EOF) {
        if (c == '\t') 
            printf("\\t");
        else if (c == '\b') 
            printf("\\b");
        else if (c == '\\') 
            printf("\\");
        else 
            putchar(c);
    }
}