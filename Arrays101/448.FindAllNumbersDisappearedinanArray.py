class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans=list()
        for i in range(0,len(nums)):
            tmp=abs(nums[i])-1
            if nums[tmp]>=0:
                nums[tmp]=-nums[tmp]
        for i in range(0,len(nums)):
            if nums[i]-1>=0:
                ans.append(i+1)
        return ans
        
