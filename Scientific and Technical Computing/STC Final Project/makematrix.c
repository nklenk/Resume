#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "parameters.h"




double matrix(char letter1, char letter2)
{
 int row;
 int column;
 char letters[23] = {'A', 'R', 'N', 'D', 'C', 'Q', 'E', 'G', 'H', 'I', 'L', 'K',                    
                     'M', 'F', 'P', 'S', 'T', 'W', 'Y', 'V', 'B', 'Z', 'X',};
  
  int k;
  int l;

  for (k = 0; k < 23; k++){
    if (letters[k] == letter1){
      row = k;}}
  for (l = 0; l < 23; l++){
    if (letters[l] == letter2){
      column = l;}}

  int i;
  int j;

/*matrix*/
/*Use double , you have floating numbers not int*/

double** mat=malloc(23*sizeof(double*)); 
for(i=0;i<23;++i)
mat[i]=  malloc(23*sizeof(double));


  FILE *file;
  file=fopen("matrix.txt", "r");

 for(i = 0; i < 23; i++)
  {
      for(j = 0; j < 23; j++) 
      {
       if (!fscanf(file, "%lf", &mat[i][j])) 
           break;
        //Use lf format specifier, \n is for new line
       if (mat[i][j] < 0){
       }
       
      }
  }
  fclose(file);
  double result;
  result = mat[row][column];
  return result;

}
