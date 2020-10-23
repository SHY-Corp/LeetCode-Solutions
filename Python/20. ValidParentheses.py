"""
Title -> ValidParenthesis (https://leetcode.com/problems/valid-parentheses/)

Approach for the solution :

Initialise a hashmap for mapping brackets and a set for opening parentheses.
Use stack to keep track of opening parentheses. 
For each character in string, if the first character is in the open_bracket set then
push it onto the stack, check the mapping of closing bracket and if it's there then 
pop it out of the stack. 

At the end if the stack is empty then the string is valid otherwise it is not.

"""
class Solution:
    
    def isValid(self, s):
        
        bracket_mapping = {"(": ")", "[": "]",  "{": "}"}
        
        open_bracket = set(["(", "[", "{"])
        
        stack = []
        
        for char in s:
            if char in open_bracket:
                stack.append(char)
            elif stack and char == bracket_mapping[stack[-1]]:
                    stack.pop()
            else:
                return False
            
        return stack == []