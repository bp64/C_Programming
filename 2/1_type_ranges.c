#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
  printf("CHAR MIN-MAX: %d, %d\n", CHAR_MIN, CHAR_MAX);
  printf("INT MIN-MAX: %d, %d\n", INT_MIN, INT_MAX);
  printf("FLOAT MIN-MAX: %.2f, %.2f\n", FLT_MIN, FLT_MAX);

  return 0;
}

