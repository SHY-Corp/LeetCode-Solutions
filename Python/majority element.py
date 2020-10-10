class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        number = nums.pop()            
        count = 1
        while nums:
            a = nums.pop()            
            if count==0:
                number = a
                count = 1
            else:
                if a==number:
                    count += 1
                else:
                    count -= 1                        
        return number