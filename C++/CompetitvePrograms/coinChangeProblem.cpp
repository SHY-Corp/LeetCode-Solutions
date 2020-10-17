#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c,r;
    int *coins,**arr;
    cin>>c>>r;
    coins=new int[r];
    
    arr=new int*[r+1];
    for(int i=0;i<r+1;i++)
    arr[i]=new int[c+2];
    
	for(int i=0;i<r;i++)
    {
        cin>>coins[i];
        arr[i+1][0]=coins[i];
    }
    for(int i=1;i<c+2;i++)
    arr[0][i]=i-1;
    arr[0][0]=0;
    for(int i=1;i<r+1;i++)
    {
        for(int j=1;j<c+2;j++)
        {
            if(i==1)
            {
                if(j==1)
                arr[i][j]=1;
                else if(arr[0][j]<arr[i][0])
                arr[i][j]=0;
                else if(arr[0][j]%arr[i][0]==0)
                arr[i][j]=1;
                else arr[i][j]=0;
            }
            else
            {
                if(arr[0][j]<arr[i][0])
                arr[i][j]=arr[i-1][j];
                else
                {
                    int sum=arr[i-1][j];
                    sum+=arr[i][(arr[0][j]-arr[i][0])+1];
                    //cout<<"arr[0][j]-arr[i][0] = "<<arr[0][j]-arr[i][0]<<" arr[i-1][j]= "<<arr[i-1][j]<<" sum = "<<sum<<"\n";
                    arr[i][j]=sum;
                }
            }
        }
    }
    for(int i=0;i<r+1;i++)
    {
    	for(int j=0;j<c+2;j++)
    	{
    		cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
    cout<<arr[r][c+1]<<"\n";
}
