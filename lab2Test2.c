/* Transpose of a Matrix in c */

#include<stdio.h>

int main()
{
 int i, j, rows, columns, a[10][10], b[10][10];
  
 printf("\nPlease Enter Number of rows and columns\n");
 scanf("%d %d", &i, &j);
 
 printf("\n Please Enter the Array Elements \n");
 for(rows = 0; rows < i; rows++)
  {
   for(columns = 0;columns < j; columns++)
    {
      scanf("%d", &a[rows][columns]);
    }
  }
 
 //Transpose of matrix 
 for(rows = 0; rows < i; rows++)
  {
   for(columns = 0;columns < j; columns++)
    {
      b[columns][rows] = a[rows][columns];
    }
  }

 printf("\n Transpose Matrix Elemnts are: \n");
 for(rows = 0; rows < j; rows++)
  {
   for(columns = 0; columns < i; columns++)
    {
      printf("%d \t ", b[rows][columns]);
    }
    printf("\n");
  }
 
return 0;
} 
