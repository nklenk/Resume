/*
 * Jacobi.c
 *
 *  Created on: Oct 26, 2015
 *      Author: Neil Klenk
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){

int i, j, k, p, n, converge;
double sum;
double A[3][3];
double B[3], X[3], X_new[3], error[3];
double eps = 0.00000000001;

A[0][0] = 1; A[0][1] = 1; A[0][2] = 2;
A[1][0] = 2; A[1][1] = 3; A[1][2] = 5;
A[2][0] = 3; A[2][1] = 3; A[2][2] = 6;

B[0] = 12;
B[1] = 18;
B[2] = 33;

X[0] = 0; 		X[1] = 0;		X[2] = 0;
X_new[0] = 0;	X_new[1] = 0;	X_new[2] = 0;


printf("Enter your guess for X0, X1, X2 separated by spaces (not zero)\n");
scanf("%lf %lf %lf", &X[0], &X[1], &X[2]);

k = 0;
	while(abs(X_new[0] - X[0])> eps || abs(X_new[1] - X[1])> eps || abs(X_new[2] - X[2])> eps){
	printf("Iteration number %d\n", k);
		for(i=0; i<3; i++){ //begin solving for new X[i] values
			if(k>0){//past first iteration
				for(p=0; p<3; p++){
				X[p] = X_new[p]; //Begin solving for a new set of X
				}
			}
			sum = 0;
			for(j=0; j<3; j++){
				if(j!=i){ //skips diagonal
				sum = sum + (A[i][j]*X[j]);
				}
			}
		X_new[i] = (B[i] - sum)/A[i][i];
		printf("X[%d] = %lf\n", i, X_new[i]);
		}
	k++;

		for(i=0; i<3; i++){
			if(abs(X_new[0]-X[0]) < eps && abs(X_new[1]-X[1]) < eps && abs(X_new[2]-X[2]) < eps){
			converge = 1;
			}
			else{
			converge = 0;
			}
				if(converge){
				printf("Converged\n");
				printf("X[%d] = %lf\n", i, X[i]);
				error[i] = abs(X_new[i]-X[i]);
				printf("Error: X[%d]: %lf\n", i, error[i]);
				k = n; //to exit loop
				}
		}

	}
}
