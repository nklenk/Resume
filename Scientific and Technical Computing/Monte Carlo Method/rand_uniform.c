/*
 * rand_uniform.c
 *
 *  Created on: Nov 14, 2015
 *      Author: Neil Klenk
 */
#include <stdio.h>
#include <stdlib.h>

#define n 100000
int i;

double X[n];

double uniform_distribution(double most, double least) {
    double Random = rand()/(RAND_MAX);
    double range = most - least + 1;
    double Rand_scaled = (Random * range) + least;
    return Rand_scaled;
}
int main(){

FILE *ptr_file;
int x;

ptr_file = fopen("rand_uniform.dat", "w");
if (!ptr_file){
	return 1;
}
for(i=0; i<n; i++){
	X[i] = uniform_distribution(5,-5.0);
	printf("%lf\n", X[i]);
}

for(i=0; i<n; i++){
	fprintf(ptr_file, "%lf\n", X[i]);
}
}
