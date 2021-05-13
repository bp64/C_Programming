#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
  printf("%d\n", setbits(21, 3, 3, 13));
  return 0;
}

// given bits x, find the right n most bits from position p and
// replace them with the right n most bits from y
// ex. setbits(21, 3, 3, 13)
//     21 -> 0b10101, 15 -> 0b1101
//     get the 3 rightmost bits from 13, 0b101
//     get the 3 bits after the 3rd from the right most bit in 21, 0b010
//     replace those bits and output resultant number, 0b11011 -> 27 
unsigned setbits(unsigned x, int p, int n, unsigned y) {
  unsigned a,b,c,d,e,f,g = 0;

  // start with x
  // 0b10101 - x
  // 1110001 - 0 the bits to replace in a series of ones
  // 0010001 - AND the two - bits to be replaced will be zeroed
  a = ~(~0 << n); // 00000111
  b = ~(a << (p+1-n)); // 11110001
  c = x & b; // 0s bits to be replaced in x

  // now work with y
  // 0b1101 - y
  // 000111 - zero the bits that won't be replaced
  // 000101 - AND the two - only the bits to be replaced are left

  d = ~(~0 << n); // 00000111
  e = y & d; // keeps the last 3 bits of y

  // 0001010 - align the replacement bits with the original, filling with 0s
  // 0010001 - modified x
  // 0011011 - OR result, bits have been replaced
  f = e << (p+1-n); // shift bits over to so it lines up with x
  g = c | f; // write replacement bits in
  
  return g;
}

