// Leetcode Problem 921

// Given a string S of '(' and ')' parentheses, we add the minimum number of
//parentheses ( '(' or ')', and in any positions ) so that the resulting
//parentheses string is valid.



class Solution {
public:
    int minAddToMakeValid(string S) {
        int count = 0, l = 0; 
        // count will store the number of opening/closing parentheses required 
        // l will store number of close parentheses which does not have any
        // matching opening parentheses.
        
        for (int i=0; i<S.length(); i++)
        {
            if (S[i] == '(') 
            {
                if(count<0) // for ex ")))()" we store number of open braces
                {
                    l += 0-count;
                    count=0;
                }
                ++count; // for '(' increase count value
            }
               
            else
                --count;  // for ')' decrease count value as we have matching pairs
        }
        
        return  abs(count)+l;  // count may be +ve or -ve so take abs value
    }
};