#Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

#in this problem we used the Counter object which when we pass a list to it, it returns a dictionnary that has the lists's elemnts as keys and their 
# occurences as values


class Solution(object):
    def majorityElement(self, nums):
        c=dict(Counter(nums))   # c is now a dictionnary that has the elements of nums as keys and their number of occurences in that list as values
        maxi=max(c.values())    # maxi is the highest number of occurences
        for key,value in c.items():   # we are now looping through the dictionnary items to return the coresponding value
            if ( value  == maxi ):     # we found the element with the highest number of occurence
                return key