#include <stdio.h>

/* REturns x with the n bits that begin at position p inverted */

unsigned invert(unsigned x, int p, int n);

int main() {
  unsigned x = 0xBB; // 1011 1011;
  int p = 3;
  int n = 4;  

  x = invert(x, p, n);
  printf("%x ", x);
}


// unsigned invert(unsigned x, int p, int n)
// {
//     unsigned y = x;
//     return ((~((~((~(unsigned int)0 << (32 - n)) >> (32 - p - n))) & (~x))) & (~(((y << (32 - p - n)) >> (32 - n)) << p)));
// }

/* second option */
unsigned invert(unsigned x, int p, int n)
{
    return (~((~((~(unsigned int)0 << (32 - n)) >> (32 - p - n))))) ^ x; // Mask 01111000
}
