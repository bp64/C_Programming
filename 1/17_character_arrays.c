// had seg faults (infinite loop) and conflicting types (getline is in stdio)

#include <stdio.h>
#define MAXLINE 1000 // max input line

int get_line(char line[], int maxlimit);
void copy(char to[], char from[]);

// print longest input line
int main()
{
  int len, max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  // while there is a line to get
  while ((len = get_line(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0) // if there was a line
    printf("%s/n", longest);
  return 0;
}

// read a line, return the len
// note this function alters the char[] passed in - pass by reference
int get_line(char s[], int lim) {
  int c, i;

  // read chars, stop until we're one below the maxline or EOF or newline
  for (i=0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  // add the newline and increment count
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0'; // add the null character to signal the end of char array
  return i;
}

// copy 'from' into 'to'; assume it's big enough
// notice, arrays are pass by REFERENCE - we are altering the original arrays
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}

