/*
 * Gram_S.c
 *
 *  Created on: Nov 14, 2015
 *      Author: Neil Klenk
 */

#include <stdio.h>
#include <math.h>

#define n 3

int main(){
int i, j;
double V1[n], V2[n], V3[n];
double U1[n], U2[n], U3[n];
double e1[n], e2[n], e3[n];

V1[0] = 10;	V1[1] = 2;	V1[2] = 3;
V2[0] = 4;	V2[1] = 25;	V2[2] = 6;
V3[0] = 7;	V3[1] = 8;	V3[2] = 19;


double V2U1, V3U1, V3U2;
double U1U1, U2U2;
double magU1, magU2, magU3;
for(i=0; i<n; i++){
	U1[i] = V1[i];
	V2U1 += V2[j]*U1[j];
	U1U1 += U1[j]*U1[j];
}
for(i=0; i<n; i++){
	U2[i] = V2[i] - (V2U1/U1U1)*U1[i];
}
for(i=0; i<n; i++){
	V3U1 += V3[i]*U1[i];
	V3U2 += V3[i]*U2[i];
	U2U2 += U2[i]*U2[i];
}
for(i=0; i<n; i++){
	U3[i] = V3[i] - (V3U1/U1U1)*U1[i] - (V3U2/U2U2)*U2[i];
}

printf ("The orthogonal vectors are:\n");
for (i=0; i<n; i++){
	printf ("U1[%d]: %lf; ", i, U1[i]);
}
printf("\n");
for (i=0; i<n; i++){
	printf ("U2[%d]: %lf; ", i, U2[i]);
}
printf("\n");
for (i=0; i<n; i++){
	printf ("U3[%d]: %lf; ", i, U3[i]);
}
printf("\n");
printf("\n");
magU1 = sqrt(pow(U1[0], 2)+ pow(U1[1], 2)+ pow(U1[2], 2));
magU2 = sqrt(pow(U2[0], 2)+ pow(U2[1], 2)+ pow(U2[2], 2));
magU3 = sqrt(pow(U3[0], 2)+ pow(U3[1], 2)+ pow(U3[2], 2));

for (i=0; i<n; i++){
	e1[i] = U1[i]/magU1;
	e2[i] = U2[i]/magU2;
	e3[i] = U3[i]/magU3;
}

printf ("The ortho-normal vectors are: \n");
for (i=0; i<n; i++){
	printf ("e1[%d]: %lf; ", i, e1[i]);
}
printf("\n");
for (i=0; i<n; i++){
	printf ("e2[%d]: %lf; ", i, e2[i]);
}
printf("\n");
for (i=0; i<n; i++){
	printf ("e3[%d]: %lf; ", i, e3[i]);
}
printf("\n");
//print out normalized vectors
}

