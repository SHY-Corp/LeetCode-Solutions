#Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
class Solution(object):
    def singleNumber(self, nums):
        single = 0
        original = 0
        #First set function is used to find all the unqiue elements and then they are added
        for i in set(nums):
            single +=i
        #Then all the elements of the given list are added    
        for i in nums:
            original +=i
        #Variable single conmtains the sum of all unique elements and variable original contains the sum of all elements in the given list.Multiplying the sum of all the unique
        #elements by 3 and subtracting it with the sum of all the elements in the original list will leave us with the sum of the single number taken twice. Hence we divide by 2 
        # to get the single number
        return ((single * 3) - original)/2
