#include <stdio.h>

// symbolic constants
#define LOWER 0
#define UPPER 300
#define STEP 20

float fahr_to_cels(float fahr);

int main()
{
  int fahr;

  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    printf("%3d %6.1f\n", fahr, fahr_to_cels(fahr));
}

float fahr_to_cels(float fahr) {
  return (5.0/9.0) * (fahr - 32.0);
}

