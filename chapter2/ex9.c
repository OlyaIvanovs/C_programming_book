#include <stdio.h>

/* Counts the number of 1-bits in its integer argument */

int bitcount(unsigned x);

int main() 
{   
    int num = 0XD5; // 11010101;
    int num1bits = bitcount(num);
    printf("The number of 1-bits %d", num1bits);
}

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x - 1)) {
        b++;
    }

    return b;
}