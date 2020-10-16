//Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

//You have the following 3 operations permitted on a word:

//Insert a character
//Delete a character
//Replace a character
//The code is basically recursion with memeotization. it will comapre to find the minimum operation.

class Solution {
public:
    int dp[1002][1002];
    int edit(string word1,string word2,int m,int n)
    {
       // cout<<m<<" "<<n<<"/";
        if(m==0) return n;
        if(n==0) return m;
        if(dp[m][n]!=-1)
            return dp[m][n];
        if(word1[m-1]==word2[n-1])
            return dp[m][n]=edit(word1,word2,m-1,n-1);
        else
            return dp[m][n]=1+min(edit(word1,word2,m-1,n-1),min(edit(word1,word2,m,n-1),edit(word1,word2,m-1,n)));
    }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        memset(dp,-1,sizeof(dp));
        return edit(word1,word2,m,n);
        
    }
};
