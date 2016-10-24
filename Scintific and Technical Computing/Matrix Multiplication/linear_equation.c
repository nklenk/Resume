#include <stdio.h>
#define n 3

int main(){

int i, j, N, NHRS, LDA, IPIV[n], LDB, INFO;
double A[n][n], AT[n][n], B[n];

A[0][0] = 6;  A[0][1] = -2;  A[0][2] = 2;
A[1][0] = 12; A[1][1] = -8;  A[1][2] = 6;
A[2][0] = 3;  A[2][1] = -13; A[2][2] = 3;

B[0] = 16;
B[1] = 26;
B[2] = -19;


//determining the transverse to pass to fortran routine

for(i=0; i<n; i++){
	for(j=0; j<n; j++){
	AT[i][j] = A[j][i];
	}
}
N = LDA = LDB = n;
NHRS = 1;

dgesv_(&N, &NHRS, AT, &LDA, IPIV, B, &LDB, &INFO);

for (j = 0; j<n; j++){  //prints out the resultant vector 
printf("X[%i]: %.3lf \n", j, B[j]);
}

}
