/*
 * Gauss-Sidel.c
 *
 *  Created on: Oct 27, 2015
 *      Author: Neil Klenk
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){

int i, j, k, p, n, converge;
double sum;
double A[3][3];
double B[3], X[3], X_old[3], error[3];
double eps = 0.00000001;

A[0][0] = 1; A[0][1] = 1; A[0][2] = 2;
A[1][0] = 2; A[1][1] = 3; A[1][2] = 5;
A[2][0] = 3; A[2][1] = 3; A[2][2] = 6;

B[0] = 12;
B[1] = 18;
B[2] = 33;

X[0] = 0; 		X[1] = 0;		X[2] = 0;
X_old[0] = 0;	X_old[1] = 0;	X_old[2] = 0;

printf("Enter your guess for X0, X1, X2 separated by spaces (not zero)\n");
scanf("%lf %lf %lf", &X[0], &X[1], &X[2]);

k = 0;
	double sumErr = 1.0;
	//while(fabs(X[0] - X_old[0])> eps || fabs(X[1] - X_old[1])> eps ||fabs(X[2] - X_old[2])> eps){
	while(sumErr  >= eps && k<20){
	sumErr = 0.0;
	printf("Iteration number %d\n", k);
		for(i=0; i<3; i++){ //begin solving for new X[i] values
		X_old[i] = X[i];
		sum = 0;
			for(j=0; j<3; j++){
				if(j!=i){ //skips diagonal
				sum = sum + (A[i][j]*X[j]);
				}
			}
		X[i] = (B[i] - sum)/(A[i][i]);
		printf("X[%d] = %lf\n", i, X[i]);
		sumErr = fabs(X[0] - X_old[0]) + fabs(X[1] - X_old[1]) +fabs(X[2] - X_old[2]);
		}
		printf("SumErr: %lf\n", sumErr);
		printf("Err_1: %lf\n", fabs(X[0] - X_old[0]));
		printf("Err_2: %lf\n", fabs(X[1] - X_old[1]));
		printf("Err_3: %lf\n", fabs(X[2] - X_old[2]));
	k++;

	for(i=0; i<3; i++){
		if(fabs(X_old[0]-X[0]) < eps && fabs(X_old[1]-X[1]) < eps && fabs(X_old[2]-X[2]) < eps){
		converge = 1;
		}
		else{
		converge = 0;
		}
			if(converge){
			printf("Converged\n");
			printf("X[%d] = %lf\n", i, X[i]);
			error[i] = fabs(X_old[i]-X[i]);
			printf("Error: X[%d]: %lf\n", i, error[i]);
			k = n; //to exit loop
			}
		}

	}
}
