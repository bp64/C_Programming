#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int maxline);
int ishex(char s[]);
int ishexchar(char c);
int len(char s[]);
int htoi(char s[]);
void strip_line(char s[], char stripped_s[]);
int rightmost_nonblank_char(char s[]);
int power(int a, int b);

int main() {
  char line[MAXLINE];
  char stripped_line[MAXLINE];
  int intval;

  // get hex from user
  get_line(line, MAXLINE);

  // remove trailing \n
  strip_line(line, stripped_line);
 
  // check if hex;
  if (!ishex(stripped_line)) {
    printf("the input isn't hex\n");
    return 1;
  }

  // convert hex
  intval = htoi(stripped_line);

  // print to screen
  printf("intval: %d\n", intval);
  return 0;
}

// get line from user
int get_line(char s[], int lim){
  int i, c;

  for (i = 0; i<=lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return ++i;
}

// strip a line of trailing blank chars
void strip_line(char s[], char stripped[]) {
  int r, l, i;

  r = rightmost_nonblank_char(s);
  for (i = 0; i < r; ++i) {
    stripped[i] = s[i];
  }

  stripped[i] = '\0';
}

// return index of the furthest nonblank char
int rightmost_nonblank_char(char s[]) {
  int i, l, c;
  l = len(s);
  for (i = l; (c = s[i]) == '\n' || c == '\t'; --i) {
    ;
  }
  return --i;
}

// check char[] is valid hex
int ishex(char s[]) {
  int i;

  for (i = 0; s[i] != '\0' || s[i] == EOF; ++i) {
    if (!ishexchar(s[i])) {
      return 0;
    }
  }
  return 1;
}

// check if char is valid hex
int ishexchar(char c) {
  int isdigit = (0 <= c - '0' && 9 >= c - '0');
  int isatof = (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');

  if (isdigit || isatof) {
    return 1;
  }
  else {
    return 0; 
  }
}

// convert hex char[] to int
int htoi(char hex[]) {
  int i, l, c, val, sum;

  val = 0;
  sum = 0;
  l = len(hex);
  for (i = l; i != 0; --i) {
    if ((c = hex[i-1]) >= '0' && c <= '9') {
      val = c - '0';
    }
    else if (c >= 'a' && c <= 'f') {
      val = c - 'a' + 10;
    }
    else if (c >= 'A' && c <= 'F') {
      val = c - 'A' + 10;
    }
    sum += power(16, (l-i)) * val;
  }
  return sum;
}

int power(int base, int exponent) {
  int i, val;
  val = 1;
  for (i = exponent; i != 0; --i) {
    val *= base; 
  }
  return val;
}


// find len of str
int len(char s[]) {
  int i;

  for (i = 0; s[i] != '\0' && s[i] != EOF; ++i) {
    ;
  }
  return i;
}

