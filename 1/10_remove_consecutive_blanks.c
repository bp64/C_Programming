#include <stdio.h>

main()
{
  int c, c_1;

  c_1 = 0;
  while ((c = getchar()) != EOF) {
    if ((c == ' ') && (c_1 == ' '))
      ;
    else
      putchar(c);
    c_1 = c;
  }

}

