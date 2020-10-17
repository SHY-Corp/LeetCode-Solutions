#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,o,row,col,max;
	int **board;
	cin>>n>>o;
	board=new int*[n];
	for(int i=0;i<n;i++)
	board[i]=new int[n];
	for(int i=0;i<n;i++)
		for(int j=0;i<n;j++)
			board[i][j]=0;
    cin>>row>>col;
    board[row-1][col-1]=2;
   // if((row-1==0&&col-1==0)||(row-1==0&&col-1==n-1)||(row-1==n-1&&col-1==0)||(row-1==n-1&&col-1==n-1))
    if(row-1==0||col-1==0||row-1==n-1||col-1==n-1)
    max=(n-1)*3;
    
    while(o--)
    {
    	cin>>row>>col;
    	board[row-1][col-1]=1;
	}
	
}
