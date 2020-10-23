#include <iostream>
using namespace std;

const int n=10;
//print 0at diagonal in matrix of n*n

void diagonal(int a[][n],int a,int m)
{
  for(int i=0;i<a;i++)
    {for(int j=0;j<m;j++)
     {
     if(i!=j&&i+j+1!=a)
     a[i][j]=0;
     }
    }
    for(int i=0;i<a;i++)
    {
     for(int j=0;j<m;j++)
     {
      cout<<a[i][j]<<" ";
     }
     cout<<endl;
    }
}
 int main()
 {  
  int a[][n]={{1,2,3},
             {4,5,6},
             {7,8,9}};
  diagonal(a,3,3);
  return 0;
 }
