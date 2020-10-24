#include<iostream>
using namespace std;

int main()
{
   int n,t1=0,t2=1,nextTerm=0;
   cout<<" enter the number of terms ";
   cin>>n;
   cout<<" Fibonacci series ";
   for(int i=1;i<=n;++1)
   {
      if(i==1)
      {
         cout<<" " <<t1;
          continue;
      }
       if(i==2)
       {
         cout<<" " <<t2;
         continue;
       }
     nextTerm=t1+t2;
       t1=t2;
       t2=nextTerm;
       cout<<nextTerm<<" ";
   }
    return 0;
}
