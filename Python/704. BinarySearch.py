class Solution(object):
    def search(self, nums, target):
        #Variable low points to first index, high points to the last  
        low = 0
        high = len(nums) - 1
        #Loop will run till the low value becomes more than high or value found
        while( low <= high ):
            mid = ( low + high )//2
            if( nums[mid] == target ):
                return mid
            elif( nums[mid] < target ):
                low = mid + 1
            else:
                high = mid - 1
        #If value not found return -1
        return -1
