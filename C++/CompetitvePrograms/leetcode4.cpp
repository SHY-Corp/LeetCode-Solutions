#include<iostream>
#include<math.h>
using namespace std;
int findComplement(int num) 
    {
        int count=0,sum=0;
        while(num>0)
        {
            if(num%2==0)
            sum+=pow(2,count);
            num/=2;
            count++;
        }
        return sum;
    }
int main()
{
	int n;
	cin>>n;
	cout<<findComplement(n);
}
