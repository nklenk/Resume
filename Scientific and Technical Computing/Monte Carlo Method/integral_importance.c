/*
 * integral_importance.c
 *
 *  Created on: Nov 22, 2015
 *      Author: Neil Klenk
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 100000

int main(){

int i, num_x;
double sum, count;
double X[n], Y[i], U[i], factor_imp[n], result[n];

while (num_x<n){
U[i] = (double)rand()/RAND_MAX;
Y[i] = (double)rand()/RAND_MAX;
Y[i] = -5.0 + 10*Y[i];
	if(U[i] <= exp(-Y[i]*Y[i]/2.0)){
	num_x = num_x + 1;
	X[num_x] = Y[i];
	}
}
sum = 0.0;
count = 0.0;
for (i=0; i<n; i++){
sum = sum + 1.0*(5.0+cos(X[i]));
factor_imp[i] = sqrt(2.0*M_PI)/count;
result[i] = sum*factor_imp[i];
count++;
}


printf("10		%lf\n", result[9]);
printf("100		%lf\n", result[99]);
printf("1000	%lf\n", result[999]);
printf("10000	%lf\n", result[9999]);
printf("100000	%lf\n", result[99999]);
}
