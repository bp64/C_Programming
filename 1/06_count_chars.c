#include <stdio.h>

main()
{
  long nc;

  nc = 0;

  // ctrl + d to send an EOF char through the terminal
  while (getchar() != EOF)
    ++nc;
  printf("%ld\n", nc);
}

