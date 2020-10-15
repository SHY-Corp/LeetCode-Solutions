#Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
#There is only one duplicate number in nums, return this duplicate number.
class Solution(object):
    def findDuplicate(self, nums):
        #Traversing the list using for loop 
        for i in nums:
            #If the count of the number is more than one then the number is duplicate and is returned
            if(nums.count(i) > 1):
                return i
