"""
Goal: Finding the Kth largest element in an array.

Procedure:
	-> Creating a min heap.
	-> Finding K number of largest elements
	-> Returning the Kth element, that is, the last element from the list found in second step.
	
Input:
First entering the array.
Second entering the K value.

Output:
A single output returning the Kth largest element of the array.


Examples:
	Input: 3 2 1 5 6 4 
		   2
		   
	Output: 5
	
	
	Input: 3 2 3 1 2 4 5 5 6
		   4
		   
	Output: 4
"""

import heapq
class Solution:
    def findKthLargest(nums, k):
        heapq.heapify(nums)
        res = heapq.nlargest(k,nums)
        return res[len(res)-1]
        
arr = [int(w) for w in input().strip().split(',')]
k = int(input())
print(Solution.findKthLargest(arr, k))
