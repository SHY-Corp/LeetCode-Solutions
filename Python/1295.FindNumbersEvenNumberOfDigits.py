#we are using list comprehension to place the number that have even number of digits in a list , and then
#we used len() function to get the total number of numbers with even number if digits

class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        return len([nums[i] for i in range(len(nums)) if (len(str(nums[i])) % 2 == 0 )])