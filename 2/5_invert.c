#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main() {
  printf("%d\n", invert(21, 3, 3));
  return 0;
}

// given bits x, invert the right n most bits from position p
// ex. invert(21, 3, 3)
//     21 -> 0b10101
//     get the 3 bits after the 3rd from the right most bit in 21, 0b010
//     invert -> 0b101 and replace 0b11011 -> 27
unsigned invert(unsigned x, int p, int n) {
  unsigned a,b,c,d,e,f,g,h,i = 0;

  // single out the bits to be inverted
  a = ~(~0 << p); // 11111000 -> 00000111
  b = a << (p+1-n); // 00001110
  c = x & b; // 00010101 & 00001110 -> 00000100
  d = c >> (p+1-n); // 00000010

  // invert bits, realign with original, 0 surrounding bits
  e = (~d) << (p+1-n); // 11111010
  f = e & b; // 00001110 & 11111010 -> 00001010

  // 0 bits in original to prep for replacement
  g = ~b; // 11110001
  h = g & x; // 11110001 & 00010101 -> 00010001

  // replace bits in original
  i = h | f; // 00010001 | 00001010 -> 00011011
  return i;
}

