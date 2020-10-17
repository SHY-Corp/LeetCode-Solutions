#include<iostream>
using namespace std;

    int firstUniqChar(string s) 
    {
        int arr[26]={0};
        for(int i=0;i<s.length();i++)
        {
            arr[s[i]-97]++;
        }
        for(int i=0;i<s.length();i++)
        {
            if(arr[s[i]-97]==1)
                return i;
        }
        return -1;
    }
int main()    
{
	string s;
	cin>>s;
	cout<<firstUniqChar(s);
}
