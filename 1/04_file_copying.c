#include <stdio.h>

main()
{
  /* normally, we would use char type for char data but
  getchar function can return an EOF, which is bigger than 
  any char */
  int c;

  // get character from input stream
  c = getchar();

  // EOF is an int defined in the stdio
  while (c != EOF) {
    // put character to an output stream
    putchar(c);
    c = getchar();
  }
}

