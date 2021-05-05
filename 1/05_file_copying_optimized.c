#include <stdio.h>

main()
{
  int c;

  /* in c, an assignment expression RETURNS the value of the assignment
  so c = getchar() sets the variable c and returns the value of getchar() */
  while ((c = getchar()) != EOF)
    putchar(c);
}

