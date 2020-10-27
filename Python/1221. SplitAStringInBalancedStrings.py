# leetcode solution for split a string in balanced strings

class Solution:
    def balancedStringSplit(self, s):
        check = {'R': 0, 'L': 0}
        count=0
        for word in s:
            check[word] += 1
            if check['R'] == check['L']:
                count += 1
                check['R'] = 0
                check['L'] = 0
        return count