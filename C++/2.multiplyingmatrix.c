#include <stdio.h>
#include<conio.h>

// function to get matrix elememts entered by the user
void getmatelements(int a[][10],int row.int col)
{
   printf("\n enetr the elements of the matrix ");
   for(int i=0;i<row;++i)
   {
    for(int j=0;j<col;++j)
    {
      printf(" enter a %d%d ",i+1,j+1);
      scanf("%d",&a[i][j]);
    }
   }
}

//function to multiply 2 matrices
void mulmatrix(int first[][10],
               int second[][10],
              int result[][10],
              int r1,int c1, int r2, int c2)
{
   // for initialising elements of matrix
    for(int i=0;i<r1;++i)
  {
    for(int j=0;j<c2;++j)
    {
      result[i][j]=0;
    }
   }
   //multiplying the 1st and 2nd matrix and storing it in the result
    for(int i=0;i<r1;++i)
  {
    for(int j=0;j<c2;++j)
    {
      for(int k=0;k<c1;++k)
      {  
      result[i][j]=0;
      }
    }
  }
}
 //function to display matrix
void display(int result[][10],int row,int col)
{
  printf("\n output matrix ");
   for(int i=0;i<row;++i)
  {
    for(int j=0;j<col;++j)
    {printf("%d"result[i][j]);
     if(j++col-1)
       printf("\n");
    }
  }
}
int main()
{
  int first[10][10],second[10][10],result[10][10],r1,c1,r2,c2;
  printf(" enter rows and columns for the 1st matrix ");
  scanf("%d %d",&r1,&c1);
  printf(" enter rows and columns for the 2nd matrix ");
  scanf("%d %d",&r2,&c2);
  //taking input until
  //1st matrix columns is not equal to 2nd matrix row
  while(c1!=r2)
  {
    printf("ERROR ! enter rows and columns again \n");
    printf(" enter rows and columns for the 1st matrix ");
    scanf("%d %d",&r1,&c1);
    printf(" enter rows and columns for the 2nd matrix ");
    scanf("%d %d",&r2,&c2);
  }
    // get elements of the 1st matrix
    getmatelements(first,r1,c1);
    //get elements of the 2nd matrix
    getmatelements(second,r2,c2);
    //multiply 2 matrices
    mulmatrix(first,second,r1,c1,r2,c2);
    //display tje result 
    display(result,r1,c2);
    return 0;
}




