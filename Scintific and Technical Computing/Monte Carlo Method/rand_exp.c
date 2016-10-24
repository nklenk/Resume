/*
 * rand_exp.c
 *
 *  Created on: Nov 15, 2015
 *      Author: Neil Klenk
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 100000

int i;
double X[n], U[n];

int main(){

FILE *ptr_file;

for (i=0; i<n; i++){
	U[i] = (double)rand()/RAND_MAX;
	X[i]= -3.0*log(1-U[i]);
}
ptr_file = fopen("rand_exp.dat", "w");
if (!ptr_file){
	return 1;
}

for(i=0; i<n; i++){
	fprintf(ptr_file, "%lf\n", X[i]);
}
}




