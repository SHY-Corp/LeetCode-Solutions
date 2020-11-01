'''
Time: O(bits of num)
Space: O(bits of num)
'''

class Solution:
    def numberOfSteps (self, num: int) -> int:
        
        digits = f'{num:b}'
        return digits.count('1') - 1 + len(digits)
