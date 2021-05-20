// polish calculator
// (1 - 2) * (4 + 5) -> 1 2 - 4 5 + *
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100 // max depth of val stack
#define BUFSIZE 100

void push(double f);
double pop();
double top();
int getop(char s[]); // get the type of operator, num, +, *, /, etc
int getch(void);
void ungetch(int);

int sp = 0; // next free position on the stack
double val[MAXVAL]; // stack
char buf[BUFSIZE]; // buffer for getch, ungetch
int bufp = 0; // next free position in buf

int main() {
  int type;
  double op2;
  char s[MAXOP]; // buffer for reading each operation

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER: // if it's a number value, read the buffer, cast to double, push to stack
      push(atof(s));
      break;
    case '+': // add the last two values on the stack
      push(pop() + pop());
      break;
    case '-':
      op2 = pop(); // pop() - pop() not evaluated left to right, so must define var first
      push(pop() - op2);
      break; 
    case '*':
      push(pop() * pop());
      break;
    case '/':
      if ((op2 = pop()) != 0.0) {
        push(pop() / op2);
      }
      else {
        printf("error: zero division error\n");
      }
      break;
    case '%':
      if ((op2 = pop()) != 0) {
        push((int) pop() % (int) op2);
      }
      else {
        printf("error: modulus of zero");
      }
      break;
    case 't':
      printf("\t%.8g\n", top());
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command '%s'\n", s);
      break; 
    }
  }
  return 0;
}

// push operands onto the stack
void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  }
  else {
    printf("error: stack full and can't be pushed\n");
  }
}

// pop operands off the top of the stack
double pop() {
  if (sp > 0) {
    return val[--sp];
  }
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

double top() {
  return val[sp - 1];
}

// get the operation or operand
int getop(char s[]) {
  int i, c;

  // set s[0] to the first non space/tab char
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0'; // make string

  if (!isdigit(c) && c != '.' && c != '-') // if not a number, it must be an operator or junk value
    return c;

  i = 0;
  if (isdigit(c) || c == '-') { // if c was a digit, get the rest of the number, if there are more digits
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0'; // end char array
  if (c != EOF)
    ungetch(c); // put char back into input
  return NUMBER;
}

// return a char on the buffer if exists, else get char from input
int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

// if space on the buffer, put char on the buffer
void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

