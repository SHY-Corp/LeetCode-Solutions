//Problem 22 - Generate Parenthesis

//Given n pairs of parentheses, write a function to 
//generate all combinations of well-formed parentheses.

//Example
//Input:
    // n = 3
// Output:
    // ((()))
    // (()())
    // (())()
    // ()(())
    // ()()()

/*
Explanation:
    We'll initially have an empty string.
    Then if the number of starting parenthesis is lesser than the input, we'll add a starting parenthesis and make a recursive call.
    If the no. of ending parenthesis is lesser than staring one, add it to the string and make a recursive call.
    If the length of the string is eqal to the required no. of brackets, add the string to the answer vector. 
*/

class Solution {
    
    void helper(string curr, int s, int e, int n, vector<string>& ans){
        
        if(curr.length()== n*2){
            ans.push_back(curr);
            return;
        }
        
        if(s< n)
            helper(curr+'(', s+1, e, n, ans);
        if(e< s)
            helper(curr+')', s, e+1, n, ans);
        
    }
    
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        helper("", 0, 0, n, ans);
        return ans;
        
    }
};