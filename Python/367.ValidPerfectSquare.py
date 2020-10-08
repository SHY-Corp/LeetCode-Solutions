#Given a positive integer num, write a function which returns True if num is a perfect square else False.
class Solution(object):
    def isPerfectSquare(self, num):
        low=0
        high=num
        #Starting from zero till the number we need to check for perfect square
        while(low<=high):
            #Calulating middle value by using right shift operator
            mid=(low+high)>>1
            #If the square of the middle value is equal to the number then it is a perfect square else not
            if(mid*mid==num):
                return True
            #If the square of the middle value is less than the number we increment the low variable else the high variable is decremented.
            #The loop will continue till the low value becomes more than the high value or the number is a perfect square then True will be 
            #returned
            elif(mid*mid<num):
                low=mid+1
            else:
                high=mid-1
        return False        
