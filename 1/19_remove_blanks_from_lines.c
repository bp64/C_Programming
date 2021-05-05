#include <stdio.h>

#define MAXLENGTH 1000

int get_line(char line[]);
void remove_trailing_blanks(char line[], char new_line[]);
void process_line(char line[]);

// remove trailing blanks in a line
int main() {
  /* 
  original idea: call a function that takes a char[] and returns another char[] without blanks
  doesn't work because you can't pass char[] back in functions

  next idea: pass the char[] to a function that identifies the blanks, deletes, reinsert '/0'
  doesn't work because you can't uninit/delete an array that's been inited

  next idea: copy the char[] to another char[] with the blanks removed
  worked, but tons of issues: debugging with printf statements w/o '\n' appended messed me up
  also, forgot to blacklist the newline char when scanning through for blanks
  */
  char line[MAXLENGTH];

  while (get_line(line) > 0) {
    process_line(line);
  }
  return 0;
}

void process_line(char line[]) {
    char new_line[MAXLENGTH];

    remove_trailing_blanks(line, new_line);
    printf("%s\n", new_line);
}

// returns line length
int get_line(char s[]) {
  int c, i;

  i = 0;
  while ((c = getchar()) != EOF && c != '\n') {
    s[i] = c;
    ++i;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void remove_trailing_blanks(char from[], char to[]) {
  int i, p, j;
  char c;

  i = p = 0;
  while ( (c = from[i]) != '\0') {
    // if c is not a space or tab, store as last value
    if (c != '\t' && c != ' ' && c != '\n') {
      p = i;
    }
    ++i;
  }
  for (i = 0; i <= p; ++i) {
    to[i] = from[i];
  }
  to[i] = '\0';
}

