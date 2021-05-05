#include <stdio.h>

int power(int m, int n);

int main()
{
  int i;

  for (i = 0; i < 10; ++i)
    printf("%d %d %d\n", i, power(2, i), power(-3, i));
  return 0;
}

// call by VALUE - argument values are copied into the local scope of the function
// we can modify 'n' without effecting the rest of the program
int power(int base, int n)
{
  int p;

  for (p = 1; n > 0; --n)
    p = p * base;
  return p;
}

