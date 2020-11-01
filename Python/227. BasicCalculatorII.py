# Problem link: https://leetcode.com/problems/basic-calculator-ii/

# Implement a basic calculator to evaluate a simple expression string.
# The expression string contains only non-negative integers and
# +, -, *, / operators and empty spaces.
# The integer division should truncate toward zero.

# Example 1:
#   Input: "3+2*2"
#   Output: 7

# Example 2:
#   Input: " 3/2 "
#   Output: 1

# Example 3:
#   Input: " 3+5 / 2 "
#   Output: 5

# Note:
# You may assume that the given expression is always valid.
# Do not use the eval built-in library function.


"""
Approach:
1. Segregate the string into a list with the digits and operations.
    1.1 Count the operations along the way.
2. Go through the list twice.
    2.1 Once to compute all "*" and  "/".
    2.2 Second to compute all "+" and "-".
3. Return the final element left in the expression.
"""


class Solution:
    def segregate(self, s):
        result = list()
        operator_count = {"+": 0, "-": 0, "*": 0, "/": 0}
        item = ""
        for index, char in enumerate(s):
            if char.isspace():
                if item != "":
                    result.append(int(item))
                    item = ""
            if char in ["+", "-", "*", "/"]:
                operator_count[char] += 1
                if item != "":
                    result.append(int(item))
                    item = ""
                result.append(char)
            if char.isnumeric():
                item += char
        if item != "":
            result.append(int(item))
        return result, operator_count

    def calculate(self, s: str) -> int:
        exp, operator_count = self.segregate(s)
        # print("Initial", exp)
        # print(operator_count)
        ops = {
            "+": (lambda x, y: x + y),
            "-": (lambda x, y: x - y),
            "*": (lambda x, y: x * y),
            "/": (lambda x, y: x // y),
        }
        index = 0
        while index < len(exp):
            if exp[index] in ["/", "*"]:
                exp[index - 1] = ops[exp[index]](
                                        exp[index - 1], exp[index + 1])
                exp.pop(index)
                exp.pop(index)
                index -= 1
            index += 1
        index = 0
        while index < len(exp):
            if exp[index] in ["-", "+"]:
                exp[index - 1] = ops[exp[index]](
                                        exp[index - 1], exp[index + 1])
                exp.pop(index)
                exp.pop(index)
                index -= 1
            index += 1
        return exp[0]
