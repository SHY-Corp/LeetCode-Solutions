/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
*/

class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char>st;
        // create a map of matching pairs of parentheses
        map<char,char>mp;
        mp[')']='(';
        mp['}']='{';
        mp[']']='[';
        int i,f=1;
        for(i=0;i<n;i++)
        {
           if(s[i]=='(' || s[i]=='{' || s[i]=='[')   //push the opening parentheses into the stack
               st.push(s[i]);
           
           else if(!st.empty() && mp[s[i]]==st.top())   //if stack is not empty and the top element is a matching opening parentheses of the current parentheses, then pop it
           {
               st.pop();
           }
           
           else                             // else the given parentheses expression is invalid
           {
               f=0;break;
           }
        }
        if(st.empty() && f==1) return true;
        
        return false;
    }
};

/*
Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false
*/
