/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).


*/


#include<bits/stdc++.h>

using namespace std;
bool dp( string &s, string &p){
        
    int a = s.length();
    int b = p.length();
    bool  t[a+1][b+1];
    memset(t,0,sizeof(t));
    
    t[0][0]=true;
    for(int i=2;i<=b;i++){
        if(p[i-1]=='*'){
            t[0][i] = t[0][i-1] || t[0][i-2];
        }
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            
            if(p[j-1]=='.' || p[j-1] == s[i-1]){
                t[i][j] = t[i-1][j-1];
            }else if(p[j-1]=='*'){
                if(j-2>=0) t[i][j]= t[i][j-2];
                if(s[i-1]==p[j-2] || p[j-2]=='.'){
                    t[i][j]= t[i][j] || t[i-1][j];
                }
            }
            
        }
    }
    return t[a][b];
        
    
}
int main(){
ios_base::sync_with_stdio(false); cin.tie(0);
cout.precision(10); cout<<fixed;

string s, p ; cin>> s >> p ;

if(dp(s,p))
cout<<true;
else
{
	cout<<false;
}



return 0;
}
