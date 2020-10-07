import heapq
class Solution:
    def findKthLargest(nums, k):
        heapq.heapify(nums)
        res = heapq.nlargest(k,nums)
        return res[len(res)-1]
        
arr = [int(w) for w in input().strip().split(',')]
k = int(input())
print(Solution.findKthLargest(arr, k))
