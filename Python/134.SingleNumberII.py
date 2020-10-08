#Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
#-----------------------Test Example-----------------------
#Input = 1,1,3,1
#Output = 3
#-----------------------Test Example2-----------------------
#Input = 0,1,0,1,0,1,9
#Output = 9

"""
This Code checks the number from array that appears only once using dictionary.
Time Complexity  = O(n) i.e. Linear Time Complexity
"""


class Solution:
    def find(self, nums):
        count = dict()
        #counting appearance of each number in array and updating the count
        for i in nums:
            count[i] = count.get(i,0) + 1
        
        # getting the number from dictionary that appears once
        for key,value in count.items():
            if value == 1:
                return key

#taking input from user of all array elements  
nums = list()
c = 0
print("Enter Numbers in the array")
print("When done with entering numbers enter \"q\"")
while c == 0:
    n = input()
    if n == 'q' or n == 'Q':
        break
    try:
        n = int(n)
    except:
        print("Enter Numbers only")
        continue
    nums.append(n)
obj = Solution() #class object
print("\n")
print(obj.find(nums), "appears once") #function call
