#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,**arr;
    cin>>n;
    arr=new int*[n];
    for(int i=0;i<n;i++)
    arr[i]=new int[n];
    for(int i=0;i<n;i++)
    {
    	string s;
    	cin>>s;
    	for(int j=0;j<n;j++)
            arr[i][j]=s[j]-48;
	}  
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0||j==0||i==n-1||j==n-1)
            {
                cout<<arr[i][j];
            }
           else if(arr[i][j]>arr[i-1][j]&&arr[i][j]>arr[i][j-1]&&arr[i][j]>arr[i+1][j]&&arr[i][j]>arr[i][j+1])
            cout<<"X";
            else cout<<arr[i][j];
        }
        cout<<"\n";
    }
}

