#include <stdio.h>

#define MAXLINE 1000

void get_line(char line[]);
void reverse_string(char s[], char s_reversed[]);
int len(char s[]);

int main() {
  char line[MAXLINE], reversed_line[MAXLINE];

  // read line from input
  get_line(line);
  // reverse line
  reverse_string(line, reversed_line);
  printf("%s\n", reversed_line);
  return 0;
}

void get_line(char line[]) {
  int c, i;

  for (i = 0; i<=MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
}

void reverse_string(char s[], char s_reversed[]) {
  int line_len, i;

  // find len of line
  line_len = len(s);
  // reverse
  for (i = line_len; i != 0; --i) {
    s_reversed[line_len-i] = s[i-1];
  }
  s_reversed[line_len] = '\0';
}

int len(char s[]) {
  int i, c;

  i = 0;
  while ((c = s[i]) != '\0')
    ++i;
  return i;
}

