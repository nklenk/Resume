#include <stdio.h>
#include <stdlib.h>
#define n 5
#define A(i,j) a[(i) + (j)*n]
#define I(i,j) q[(i) + (j)*n]
#define B(i,j) b[(i) + (j)*n]
#define C(i,j) c[(i) + (j)*n]
#define D(i,j) d[(i) + (j)*n]

int main(){

int i, j, k, N, NHRS, LDA, LDB, INFO;
double *a = malloc(n*n*sizeof(double));
double *q = malloc(n*n*sizeof(double));
double *b = malloc(n*n*sizeof(double));
double *c = malloc(n*n*sizeof(double));
double *d = malloc(n*n*sizeof(double));
int *ipiv = malloc(n*n*sizeof(int));
double sum;

// Matrix A
A(0,0) = 1.0;     A(0,1) = 1.0/2.0; A(0,2) = 1.0/3.0; A(0,3) = 1.0/4.0; A(0,4) = 1.0/5.0;
A(1,0) = 1.0/2.0; A(1,1) = 1.0/3.0; A(1,2) = 1.0/4.0; A(1,3) = 1.0/5.0; A(1,4) = 1.0/6.0;
A(2,0) = 1.0/3.0; A(2,1) = 1.0/4.0; A(2,2) = 1.0/5.0; A(2,3) = 1.0/6.0; A(2,4) = 1.0/7.0;
A(3,0) = 1.0/4.0; A(3,1) = 1.0/5.0; A(3,2) = 1.0/6.0; A(3,3) = 1.0/7.0; A(3,4) = 1.0/8.0;
A(4,0) = 1.0/5.0; A(4,1) = 1.0/6.0; A(4,2) = 1.0/7.0; A(4,3) = 1.0/8.0; A(4,4) = 1.0/9.0;

// Identity Matrix
I(0,0) = 1; I(0,1) = 0; I(0,2) = 0; I(0,3) = 0; I(0,4) = 0;
I(1,0) = 0; I(1,1) = 1; I(1,2) = 0; I(1,3) = 0; I(1,4) = 0;
I(2,0) = 0; I(2,1) = 0; I(2,2) = 1; I(2,3) = 0; I(2,4) = 0;
I(3,0) = 0; I(3,1) = 0; I(3,2) = 0; I(3,3) = 1; I(3,4) = 0;
I(4,0) = 0; I(4,1) = 0; I(4,2) = 0; I(4,3) = 0; I(4,4) = 1;

//Printing matrix A
printf("A\n");
for(i = 0; i<n; i++){
printf("%16.6lf %16.6lf %16.6lf %16.6lf %16.6lf\n", A(i,0), A(i,1), A(i,2), A(i,3), A(i,4));
printf("\n");
}

N = LDA = n;
NHRS = LDB = 5;

dgesv_(&N, &NHRS, a, &LDA, ipiv, q, &LDB, &INFO);

printf("info: %d \n", INFO);
printf("\n");
//Returns I as A^-1

printf("A^-1\n");
for(i = 0; i<n; i++){
printf("%16.6lf %16.6lf %16.6lf %16.6lf %16.6lf\n", I(i,0), I(i,1), I(i,2), I(i,3), I(i,4));
printf("\n");
}

// A^-1*A
for(i = 0; i<n; i++){
	for (j = 0; j<n; j++){
	sum = 0;
		for(k = 0; k<n; k++){
		sum = sum + I(i,k)*A(k,j);
		B(i,j)=sum;
		}
	}
}
printf("A^-1 *A\n");
for(i = 0; i<n; i++){
printf("%16.6lf %16.6lf %16.6lf %16.6lf %16.6lf\n", B(i,0), B(i,1), B(i,2), B(i,3), B(i,4));
printf("\n");
}

//A*A^-1
for(i = 0; i<n; i++){
	for (j = 0; j<n; j++){
	C(i,j) = 0;
		for(k = 0; k<n; k++){
		C(i,j) = C(i,j) + A(i,k)*I(k,j);
		}
	}
}
printf("A* A^-1\n");
for(i = 0; i<n; i++){
printf("%16.6lf %16.6lf %16.6lf %16.6lf %16.6lf\n", C(i,0), C(i,1), C(i,2), C(i,3), C(i,4));
printf("\n");
}

//Use dgemm to check
double alpha = 1, beta = 1;
char TRANSA = N, TRANSB = N;
int M = n, K = n , LDC = n;
cblas_dgemm(TRANSA, TRANSB, M, N, K, alpha, a, LDA, q, LDB, beta, d, LDC);

// A^-1*A
for(i = 0; i<n; i++){
	for (j = 0; j<n; j++){
	D(i,j) = 0;
		for(k = 0; k<n; k++){
		D(i,j) = D(i,j) + I(i,k)*A(k,j);
		}
	}
}
printf("for DGEMM routine: A^-1*A\n");
for(i = 0; i<n; i++){
printf("%16.6lf %16.6lf %16.6lf %16.6lf %16.6lf\n", D(i,0), D(i,1), D(i,2), D(i,3), D(i,4));
printf("\n");
}

}
