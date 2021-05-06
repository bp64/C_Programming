#include <stdio.h>
#define MAXLINE 1000 // max input line

// declare the external variables here
int max;
char line[MAXLINE];
char longest[MAXLINE];

int get_line(void);
void copy(void);

int main()
{
  int len;
  // tell function to get these vars externally
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = get_line()) > 0)
    if (len > max) {
      max = len;
      copy();
    }
  if (max > 0) 
    printf("%s/n", longest);
  return 0;
}

int get_line() {
  int c, i;
  extern char line[];

  for (i=0; i<MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void copy() {
  int i;
  extern char longest[], line[];

  i = 0;
  while((longest[i] = line[i]) != '\0')
    ++i;
}
