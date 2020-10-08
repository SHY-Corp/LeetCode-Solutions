#Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
class Solution(object):
    def majorityElement(self, nums):
        tot = len(nums)/2
        ls=[]
        #First we find the unique element in the list
        for i in set(nums):
            count = 0
            #Then we count the number of occurrences of the element in the list 
            for j in nums:
                if( i == j):
                    count += 1
                #After that we append the unique element and the number of occurences of the element to the list named ls
                ls.append([i,count])
        for i in range(len(ls)):
            #Here we check occurence of which element is greater than n/2 and return it
            if( ls[i][1] > tot):
                return ls[i][0]
