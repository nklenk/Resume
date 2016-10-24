/*
 * ranr_normal.c
 *
 *  Created on: Nov 24, 2015
 *      Author: Neil Klenk
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 100000

int main(){

double Y[n], U[n], X[n];
int i, num_x;
num_x = 0;
i = 0;

FILE *ptr_file;

while (num_x<n){
U[i] = (double)rand()/RAND_MAX;
Y[i] = (double)rand()/RAND_MAX;
Y[i] = -5.0 + 10*Y[i];
	if(U[i] <= exp(-Y[i]*Y[i]/2.0)){
	num_x = num_x + 1;
	X[num_x] = Y[i];
	}
}

ptr_file = fopen("rand_normal.dat", "w");
	if(!ptr_file){
		return 1;
	}
for(i=0; i<n; i++){
	fprintf(ptr_file, "%lf\n", X[i] );
}
}

