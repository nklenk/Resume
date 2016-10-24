#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "parameters.h"

double main(){
  char letter1 = 'F';
  char letter2 = 'Y';
  double val;
  val = matrix(letter1, letter2);

  printf("\n");
  printf("The value of matrix[%c][%c] is : %1.1lf", letter1, letter2, val);
  printf("\n");
  return 0;
  }

