/*
Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

    0 <= i <= s.length - 2
    s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.

To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.
Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.
*/

class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string ans;
        if(n==0) return ans;
        
        stack<char> st;
        st.push(s[0]);
        for(int i=0;i<n-1;i++){
            if(st.empty()) st.push(s[i+1]);
            else {
                int elt  = st.top();
                if( (elt>96 && elt==s[i+1]+32) || (elt<96 && elt==s[i+1]-32) ) 
                    st.pop();
                 else st.push(s[i+1]);   
            }
        }
        
        while(!st.empty()){
             ans=st.top()+ans;
             st.pop();   
        }
        return ans;
    }
};