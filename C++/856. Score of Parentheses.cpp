/*
Aim : Calculate the score of a given vaild expression (parentheses), acc to given rules

Soln : We can use an stack to store the '(' char and when a ')' is encountered the we either
       1. Return the score if > ()
       2. Return the score of inner parentheses > ((...)..)

*/
class Solution {
public:
    int scoreOfParentheses(string S) {
        
        stack<int> m_stack;
        m_stack.push(0); // to keep the total score
        for(char c:S){
            if(c=='(')
                m_stack.push(0); //When meets '(', just push a zero to stack
            else{
                int tmp=m_stack.top(); //  balance the last '(', it stored the score of inner parentheses
                m_stack.pop();
                int val=0;
                if(tmp>0) // not zero means inner parentheses exists and double it
                    val=tmp*2;
                else // zero means no inner parentheses, just using 1
                    val=1;
                m_stack.top()+=val; // pass the score of this level to parent parenthese
            }   
        }
        return m_stack.top();
    }
};
