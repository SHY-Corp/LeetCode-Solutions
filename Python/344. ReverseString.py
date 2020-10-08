#Function to reverse a string
class Solution(object):
    def reverseString(self, s):
        #Taking variables that point to the starting and end position
        i=0
        j=len(s) - 1
        while(i <= j):
            #Swapping the starting and the ending value
            s[i] , s[j] = s[j] , s[i]
            #Incrementing the variable that points to the starting position and decrementing the variable that points to the last position.
            #The loop will continue till the variable pointing the starting value becomes more than the one pointing the ending value.
            #This will assure all the characters in the string are swapped. Hence reversing the string
            i +=1
            j -=1
