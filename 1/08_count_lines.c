#include <stdio.h>

main()
{
  int c, nl;

  nl = 0;

  // note we don't need brackets for this multiline expression
  while ((c = getchar()) != EOF)
    // a character written between single quotes is the int value
    if (c == '\n')
      ++nl;

  printf("%d\n", nl);
}

