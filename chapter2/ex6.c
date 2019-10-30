#include <stdio.h>

/* REturns x with the n bits that begin at position p set to rightmost n bits of y */

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
  unsigned x = 0xE5; // 1110 0101;
  unsigned y = 0xAB;  // 1010 1011;
  int p = 2;
  int n = 4;  

  x = setbits(x, p, n, y);
  printf("%x ", x);
}


unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return ~((~((y << (32 - n)) >> (32 - p - n))) & (~(~(~(unsigned int)0 >> (32 - n) << p) & x)));
    // return ~(~(~(unsigned int)0 >> (32 - n) << p) & x);
}
