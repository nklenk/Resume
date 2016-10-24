/*
 * pi.c
 *
 *  Created on: Nov 22, 2015
 *      Author: Neil Klenk
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 100000

int main(){


double rand_x[n], rand_y[n], eval[n], exp_x[n], exp_y[n], pi, j, k;
int i;
j = 0.0;
k=0.0;
for(i=0; i<n; i++){
rand_x[i] = (double)rand()/RAND_MAX;
//printf("X: %lf  ", rand_x[i]);
rand_y[i] = (double)rand()/RAND_MAX;
//printf("Y: %lf\n", rand_y[i]);
exp_x[i] = rand_x[i]*rand_x[i];
//printf("X^2: %lf\n", exp_x[i]);
exp_y[i] = rand_y[i]*rand_y[i];
//printf("Y^2: %lf\n", exp_y[i]);
eval[i] = (double) sqrt(exp_x[i] + exp_y[i]);
//printf("eval: %lf\n", eval[i]);
	if(eval[i] < 1 ){
	j++;
}
k++;
pi = 4.0*(j/k);

printf("#:%d     Pi: %lf\n",i, pi);
//printf("i: %d     j: %lf\n", i, j);
}
}


