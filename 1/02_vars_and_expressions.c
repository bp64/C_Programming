#include <stdio.h>

main()
{
  // declare vars
  float fahr, celsius;
  int lower, upper, step;

  // initialize vars
  lower = 0;
  upper = 300;
  step = 20;

  // print heading
  printf("%3s %6s\n", "Fahr", "Celsius");
 
  // loop and print table
  fahr = lower;
  while (fahr <= upper) {

    // 5/9 evaluates to 0 because of int division
    celsius = (5.0/9.0) * (fahr-32.0);

    // %6.1f means 6 characters wide, 2 after the decimal
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

