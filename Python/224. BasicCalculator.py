# Problem link: https://leetcode.com/problems/basic-calculator/

# Implement a basic calculator to evaluate a simple expression string.
# The expression string may contain open '(' and closing parentheses ')',
# the plus '+' or minus sign '-', non-negative integers and empty spaces .

# Example 1:
# 	Input: "1 + 1"
# 	Output: 2

# Example 2:
# 	Input: " 2-1 + 2 "
# 	Output: 3

# Example 3:
# 	Input: "(1+(4+5+2)-3)+(6+8)"
# 	Output: 23

# Note:
# 	You may assume that the given expression is always valid.
# 	Do not use the eval built-in library function.

"""
Approach:
1. Segregate the string into a list with the digits, operations
   and parenthesis.
    1. To make sure that there could be any 2,3,4... no. of digits in a number:
        1. If char is a numeric, appending it to item string.
        2. Else append item to list if not empty and then
           append what was encountered.
    2. Adding parenthesis to both sides before passing the string to segregator
       since our algorithm computes only when a ")" is encountered.
2. We have a dictionary to use for the operations.
3. Now iterate through the list. (enumerate gives index,item pairs.)
    1. Append until ")" is encountered.
    2. When ")" is encountered:
        1. Find the index of the correcponding "(".
        2. pop and operate on the numbers staring from that index,
           appending them at the same index.
           (Hence making it in-place operation(kind of))
        3. Finally when only a single number is left to compute,
           stack[-2] would be "(", so store number in temp,
           pop the "(", and add number back to stack.
        4. For eg, this makes -
            stack = ["(", 1, "+", "(", 1, "+", 2 ]
        become -
            stack = ["(", 1, "+", 3 ]
4. Finally return the last item of the stack, the computed answer.
"""


class Solution:
    def segregate(self, s: str) -> list:
        """
        Separetes elements of the equation from string to list.

        >>>segregate("(1+(4+5+2)-3)+(6+8)")
        ['(', '(', 1, '+', '(', 4, '+', 5, '+', 2, ')', '-', 3, ')', '+',
                                                 '(', 6, '+', 8, ')', ')']
        >>>segregate("( 11 + ( 41 + 51 + 21 ) - 31 ) + ( 16 + 18 )")
        ['(', '(', 11, '+', '(', 41, '+', 51, '+', 21, ')', '-', 31, ')',
                                         '+', '(', 16, '+', 18, ')', ')']

        """
        result = []
        item = ""
        for char in s:
            if char.isspace():
                if item != "":
                    result.append(int(item))
                    item = ""
            if char in ["(", ")", "+", "-"]:
                if item != "":
                    result.append(int(item))
                    item = ""
                result.append(char)
            if char.isnumeric():
                item += char
        return result

    def calculate(self, s: str) -> int:
        """
        Returns the computed value of the expression.

        >>>calculate("(1+(4+5+2)-3)+(6+8)")
        23
        >>>calculate("( 11 + ( 41 + 51 + 21 ) - 31 ) + ( 16 + 18 )")
        127

        """
        list_of_expression = self.segregate("(" + s + ")")
        # print("initial",list_of_expression)
        ops = {
            "+": (lambda x, y: x + y),
            "-": (lambda x, y: x - y),
        }
        stack = []
        for index, item in enumerate(list_of_expression):
            if item != ")":
                stack.append(item)
                # print(stack)
            else:
                open_brac = len(stack) - 1
                while stack[open_brac - 1] != "(":
                    open_brac -= 1
                while stack[-2] != "(":
                    x, op, y = (
                        stack.pop(open_brac),
                        stack.pop(open_brac),
                        stack.pop(open_brac),
                    )
                    stack.insert(open_brac, int(ops[op](x, y)))
                temp = stack.pop()
                stack.pop()
                stack.append(temp)
        return stack.pop()
