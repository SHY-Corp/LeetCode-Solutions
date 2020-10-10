#Here first mid is calculated and then value at the index is compared with the value to be found. If there is match then the index at which the match occurs is returned.
#If the value at the middle index is smaller than the value to be found we increase the variable low so as to search in the next half of the list.
#If the value at the middle index is larger than the value to be found we decrease the variable high so as to search in the first half of the list.
#This continues till the element is found, then index at which it is present is returned or low becomes more than high i.e value is not found hence -1 is returned 
class Solution(object):
    def search(self, nums, target):
        #Variable low points to first index, high points to the last  
        low = 0
        high = len(nums) - 1
        #Loop will run till the low becomes more than high or value found
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
