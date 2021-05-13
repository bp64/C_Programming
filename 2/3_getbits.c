#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main() {
  printf("%d\n", getbits(21, 3, 3));
  return 0;
}

// given num x, get the n bits from position p
// getbits(21, 3, 3) --> 21 is 0b10101, from the right, get the 3rd bit
// and the 3 bits to the right - 0b010 -> 2
unsigned getbits(unsigned x, int p, int n) {
  return 
    (x >> (p+1-n)) // (remove the rightmost unimportant bits, ex. 10101 -> 1010)
    &
    ~(~0 << n) // (left shift bits of 1s then take the complement, ex. 11111111 -> 11111000 -> 00000111)
    // then bitwise and to zero the leading digits, ex. 1010 & 0111 -> 0010 -> 2
    ;
}

