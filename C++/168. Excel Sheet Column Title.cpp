
//Problem Statement: Excel Sheet Column Title

// Given a positive integer, return its corresponding column title as appear in an Excel sheet.

// For example:

//     A -> 1
//     B -> 2
//     C -> 3
//     ...
//     Z -> 26
//     AA -> 27
//     AB -> 28 
//     ...

//Solution:

class Solution {
public:
    string convertToTitle(int n) {
     
        string ans;
                
        while(n>26) {
            
            int rem=n%26;
            n=n/26;
            
            if(rem==0){
                rem=26; n--;
            }
            ans += 'A'+rem-1;
        }
        ans += char(n+'A'-1);
        reverse(ans.begin(), ans.end()); 
        return ans;
    }
};

//Complexity: O(n)
