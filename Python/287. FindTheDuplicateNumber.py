#Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
#There is only one duplicate number in nums, return this duplicate number.
class Solution(object):

    def findDuplicate(self, nums):
        #Traversing the list using for loop
        s = sorted(nums)      #sorting given array
        a,b = 0,len(nums)
        temp=(a+b)//2
        t = 1
        while t:              #using binary search to find duplicate
            if s[temp] == temp and s[temp-1] == temp:
                return s[temp]
            if s[temp] == temp+1 and s[temp-1] == temp:
                a = temp
            else:
                b = temp
            temp = (a+b)//2
