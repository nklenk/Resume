/*
 * Mod_GS.c
 *
 *  Created on: Nov 22, 2015
 *      Author: Neil Klenk
 */
#include <stdio.h>
#include <math.h>

#define n 3
#define I(i,j) q[(i) + (j)*n]

int main(){
int i, j;
double V1[n], V2[n], V3[n];
double U1[n], U2[n], U3[n];
double e1[n], e2[n], e3[n];
double b[n], X[n], Q[n][n], R[n][n], A[n][n], Qinv[i][j], Rinv[n][n], INT[n][n];
double *q = malloc(n*n*sizeof(double));

V1[0] = 1;	V1[1] = 1;	V1[2] = 2; // Matrix A
V2[0] = 2;	V2[1] = 3;	V2[2] = 5; //
V3[0] = 3;	V3[1] = 3;	V3[2] = 6; //

// Identity Matrix
I(0,0) = 1; I(0,1) = 0; I(0,2) = 0; I(0,3) = 0; I(0,4) = 0;
I(1,0) = 0; I(1,1) = 1; I(1,2) = 0; I(1,3) = 0; I(1,4) = 0;
I(2,0) = 0; I(2,1) = 0; I(2,2) = 1; I(2,3) = 0; I(2,4) = 0;
I(3,0) = 0; I(3,1) = 0; I(3,2) = 0; I(3,3) = 1; I(3,4) = 0;
I(4,0) = 0; I(4,1) = 0; I(4,2) = 0; I(4,3) = 0; I(4,4) = 1;


for(i=0; i<n; i++){
A[0][0] = 1;	A[0][1] = 2;	A[0][2] = 3;
A[1][0] = 1;	A[1][1] = 3;	A[1][2] = 3;
A[2][0] = 2;	A[2][1] = 5;	A[2][2] = 6;
}

b[0] = 12;
b[1] = 18;
b[2] = 33;

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

for (i=0; i<n; i++){ //eqiivalent to q1->q3
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

//create Q
for(i=0; i<n; i++){
	Q[i][0] = e1[i];
	Q[i][1] = e2[i];
	Q[i][2] = e3[i];
}

//Create R
for (i=0; i<n; i++){
	for(j = i+1; j<n; j++){
	R[i][j] = A[i][j]*Q[i][j];
	}
//Create Qinv
for(i=0; i<n; i++){
	for(j=0; j<n; j++){
	Qinv[i][j] = Q[j][i];
	}
}
//Fing Rinv
int *ipiv = malloc(n*n*sizeof(int));
int N, LDA, NHRS, LDB, INFO;

N = LDA = n;
NHRS = LDB = 3;

dgesv_(&N, &NHRS, R, &LDA, ipiv, q, &LDB, &INFO);

printf("info: %d \n", INFO);
printf("\n");
//R is now Rinv

int sum, k;

for (i=0; i<n; i++){
	for (j=0; j<n; j++){
	sum =0;
		for (k=0; k<n; k++){
		sum = sum +R[j][k]*Qinv[k][j];
		INT[i][j] = sum;
		}
	}
}
//find X
for(i=0; i<n; i++){
	sum = 0;
	for(j=0; j<n; j++){
	sum = sum + INT[i][j]*b[i];
	X[i] = sum;
	}
}
for(i=0; i<n; i++){
printf("X[0]: %lf\n",X[i]);
}
}
}

