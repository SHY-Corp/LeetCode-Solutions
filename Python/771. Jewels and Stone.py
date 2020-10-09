'''
You're given strings J representing the types of stones that are jewels, and S representing the stones you have. 
Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are should be distinct, and all characters in J and S are letters. 
Letters are case sensitive, so "a" is considered a different type of stone from "A".
'''
class Solution(object):
   def numJewelsInStones(self, J, S):
      jewels = {}
      for i in J:
         jewels[i] = 1
      number = 0
      for i in S:
         if i in jewels:
            number+=1
      return number
j=input("Enter Jewels: ")
s=input("Enter Stones: ")
ob1 = Solution()
print(ob1.numJewelsInStones(j,s))