#include <iostream>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	for(int j=1;j<=t;j++)
 {
     cin>>n;
    int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	int *l,*r,temp;
	l= &arr[0];
	r= &arr[n-1];
	while(l<r)
	{
	    temp=*l;
	    *l=*r;
	    *r=temp;
	    l++;
	    r--;
	}
	for(int i=0;i<n;i++)
	{
	    cout<<arr[i]<<" ";
	}
  }
	return 0;
}
