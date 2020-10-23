/*
    PROBLEM STATEMENT:
    
    Given two strings S and T, return if they are equal when both are typed into empty text       editors. # means a backspace character.

    Note that after backspacing an empty text, the text will continue empty.
    
    Input: S = "ab#c", T = "ad#c"
    Output: true
    Explanation: Both S and T become "ac".
    
    Input: S = "a##c", T = "#a#c"
    Output: true
    Explanation: Both S and T become "c".
    
    Input: S = "a#c", T = "b"
    Output: false
    Explanation: S becomes "c" while T becomes "b".
*/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char>s1,s2;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='#')           //checking if the occured character is '#'
            {
                if(!s1.empty())     //if stack is not empty. This is done to deal with cases like a##b or ab####
                    s1.pop();       //erasing top element
            }
            else s1.push(S[i]);
        }
        for(int i=0;i<T.length();i++)
        {
            if(T[i]=='#')
            {
                if(!s2.empty())
                    s2.pop();
            }
            else s2.push(T[i]);
        }
        return s1==s2;      //checking if both are stacks are equal or not
    }
};