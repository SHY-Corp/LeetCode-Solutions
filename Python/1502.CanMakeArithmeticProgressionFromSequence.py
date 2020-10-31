#Have to figue out if the given list is in arithmetic progression or not.
class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        dif=arr[1]-arr[0]
        for i in range (2,len(arr)):
            d=arr[i]-arr[i-1]
            if d!=dif:
                return False
        return True    
