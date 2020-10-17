#include<iostream>
using namespace std;
bool canConstruct(string ransomNote, string magazine) 
    {
        int count=ransomNote.length(),j,i;
        for( i=0;i<ransomNote.length();i++)
        {
        	cout<<count;
            if(count==0)
                return true;
            for( j=0;j<magazine.length();j++)
            {
                if(magazine[j]==ransomNote[i])
                {
                    magazine[j]='*';
                    count-=1;
                    break;
                }
            }
            cout<<"\n"<<j;
            if(j==magazine.length())
                return false;
        }
        if(count==0)
        return true;
        return false;
    }
int main()
{
	string r,m;
	cin>>r>>m;
	cout<<canConstruct(r,m);
}
