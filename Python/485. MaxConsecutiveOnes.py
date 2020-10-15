#Given a binary array, find the maximum number of consecutive 1s in this array. 
#Taking two variables consecutive and result and assigning them to zero. 
#Traversing the list if the value 1 is found in the list we add 1 to consecutive. 
#If result is less than consecutive then assigning the value of consecutive to result.
#If the consecutive value is also 1 then we increment consecutive by 1 and assign its value to result if value of result is smaller 
#If the consecutive value is not 1 then we assingn 0 to consecutive and start over.
#Fianlly the max consecutive value is returned after traversing the list
class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        consecutive=0
        result=0
        for i in nums:
            if(i==1):
                consecutive += 1
                if(result < consecutive):
                        result = consecutive
            else:
                consecutive = 0
        return result
