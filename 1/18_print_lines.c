#include <stdio.h>

#define PRINTLENGTH 80
#define MAXLENGTH 1000

int get_line(char line[], int maxline);
char line[MAXLENGTH];
int len;

int main() {
  // while a line exists
  while ( (len = get_line(line, MAXLENGTH)) > 0) {
    if (len > PRINTLENGTH)
      printf("%s\n", line);
  }
}

// return len of line and set s[] as line
int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i<=lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

