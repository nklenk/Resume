/*
 * integral_unbiased.c
 *
 *  Created on: Nov 22, 2015
 *      Author: Neil Klenk
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define n 100000

int main(){
int i;
double X[n], factor_unbiased[n], result[n];
double rando, count, sum = 0.0;
count = 0.0;

//determine factor unbiased

for (i=0; i<n; i++){
rando = (double)rand()/RAND_MAX;
X[i] = -5.0 + 10.0*rando;
sum = sum + exp((-X[i]*X[i]/2.0))*(5.0+cos(X[i]));
count++;
factor_unbiased[i] = 10.0/(count);
result[i] = sum* factor_unbiased[i];
}

printf("10		%lf\n", result[9]);
printf("100		%lf\n", result[99]);
printf("1000	%lf\n", result[999]);
printf("10000	%lf\n", result[9999]);
printf("100000	%lf\n", result[99999]);
}

