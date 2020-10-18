PROBLEM -
/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

/*
Approach : 
We'll use stack datastructure to solve this problem.
If Length of string is odd then it'll never be balanced.
If it is even --
if at any point a closing bracket is obtained then if top doesn't matches it's corresponding opening
bracket we'll have unbalanced condition and at each step of violation we'll return false

At last if stack is empty then we'll have a balanced bracket string otherwise unbalanced

It's better to dry run following code and understand the process as code is quite intutive !!
*/

class Solution {
public:
    bool isValid(string s) {
        int l = s.length();
        if (l%2==1) return false;
        
        if (s[0]==')'||s[0]==']'||s[0]=='}') return false;
        
        
        stack <char> stk;
        for (int i=0;i<s.length();++i){
		if (s[i]=='(' || s[i]=='{' || s[i] == '[')
			stk.push(s[i]);

		else if (s[i]==')'){
            if (stk.empty()) return false;
			else if (stk.top()=='(') stk.pop();
            else return false;
		}

		else if (s[i]=='}'){
            if (stk.empty()) return false;
			else if (stk.top()=='{') stk.pop();
            else return false;
		}

		else if (s[i]==']'){
            if (stk.empty()) return false;
			else if (stk.top()=='[') stk.pop();
            else return false;
		}
        
        else return false;
		
	}

	if (stk.empty()) return true;
	else return false;
      
    }
};