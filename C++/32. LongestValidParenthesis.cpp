//Given a string containing just the characters 
//'(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//We can solve this by using the concept of stack. We will check for the top most closing brace and calculate max length.

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int l=s.length();
        int ans=0;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                st.pop();
                if(st.empty()){
                    st.push(i);
                    continue;
                }
                int m=i-st.top();
                ans=max(ans,m);
                
            }
        }
        return ans;
        
    
    }
};
