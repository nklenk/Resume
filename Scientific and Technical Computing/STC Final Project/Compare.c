/*
 * AT.c
 *
 *  Created on: Nov 28, 2015
 *      Author: Neil Klenk
 */
#include <stdio.h>
#include <stdlib.h>
#include "parameters.h"

int main(){

FILE *  fp;
char str[100000], buffer[100];
char ch1, ch2, ch3, ch4;
int i, count, count_2;
double  sum, sum1, sum2, sum3, sum4;
double sumvar = 14.0;

fp = fopen("fasta.txt", "r");
if(fp == NULL){
	printf("Error opening file\n");
	return(-1);
}
fgets (buffer, 100, fp);
fgets (str, 100000, fp);
rewind(fp);
fgets (buffer, 100, fp);
i=0;
count = 0;
count_2 = 0;
int stringlength = 0;
int c;

while((c = fgetc(fp)) != EOF){
stringlength += 1;
}
printf("Sequence length: %d\n", stringlength);
while (i+4 < stringlength){
	ch1 = str[i];
	ch2 = str[i+1];
	ch3 = str[i+2];
	ch4 = str[i+3];
/*
	printf("ch1: %c\n", ch1);
	printf("ch2: %c\n", ch2);
	printf("ch3: %c\n", ch3);
	printf("ch4: %c\n", ch4);
*/
	i++;

	sum1 = matrix(ch1,'H');
	sum2 = matrix(ch2,'A');
	sum3 = matrix(ch3,'F');
	sum4 = matrix(ch4,'H');

	sum = sum1+ sum2+ sum3+ sum4;
	if (sum >= sumvar){
		count++;
	}
	sum1 = matrix(ch1, 'H');
	sum2 = matrix(ch2, 'F');
	sum3 = matrix(ch3, 'A');
	sum4 = matrix(ch4, 'H');
	
	sum = sum1 +sum2+ sum3+ sum4;
	if( sum >= sumvar){
		count++;
	}
	sum1 = matrix(ch1, 'Y');
	sum2 = matrix(ch2, 'A');
	sum3 = matrix(ch3, 'S');
	sum4 = matrix(ch4, 'H');

	sum = sum1 +sum2+ sum3+ sum4;
	if( sum >= sumvar){
		count_2++;
	}
	sum1 = matrix(ch1, 'H');
	sum2 = matrix(ch2, 'S');
	sum3 = matrix(ch3, 'A');
	sum4 = matrix(ch4, 'Y');

	sum = sum1 +sum2+ sum3+ sum4;
	if( sum >= sumvar){
		count_2++;
}
}
printf("The number of Malonyl-CoA extender units is: %d\n", count);
printf("The number of Methyl-Malonyl-CoA extender units is: %d\n", count_2);


}
