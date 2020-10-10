#in this problem we used the Counter object which when we pass a list to it, it returns a dictionnary that has the lists's elemnts as keys and their 
# occurences as values


from collections import Counter
class Solution(object):
    def singleNumber(self, nums):
        c=Counter(nums)  # in this line we defind c as the dictionnary that has each element of the list as keys  and their number of occurences as values
        sorted_items=sorted(c.items(), key = lambda x:x[1])   # in this line we sorted that dictionnary based on its values , first item will be the Single Number
        return sorted_items[0][0]  #since the sorted() function returns a list of key-value pair of sorted dict, our SingleNumber is in the first pair
        
