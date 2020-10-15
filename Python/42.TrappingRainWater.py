'''
    LeetCode Link: https://leetcode.com/problems/trapping-rain-water

    Given n non-negative integers representing an elevation map where the width of each bar is 1,
    compute how much water it is able to trap after raining.

    The elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
    In this case, 6 units of rain water (blue section) are being trapped.

    Example:

    Input: [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6

    Solution: 
    Search from left to right and maintain a max height of left and right separately,
    Consider this as one-side wall of partial container. Fix the higher one and flow water from the lower part. 
    For example, if current height of left is lower, we fill water in the left bin. 
    We will do this until left meets right or we filled the whole container.

    Time Complexity: O(n)
    Space Complexity: O(1)

'''

class Solution:
    def trap(self, heights: List[int]) -> int:
        water = 0
        leftMaxHeight = 0
        rightMaxHeight = 0
        start = 0
        end = len(heights) - 1

        while start < end:
            if heights[start] < heights[end]:
                if heights[start] > leftMaxHeight:
                    leftMaxHeight = heights[start]
                else:
                    water += leftMaxHeight - heights[start]
                    start+=1
            else:
                if heights[end] > rightMaxHeight:
                    rightMaxHeight = heights[end]
                else:
                    water += rightMaxHeight - heights[end]
                    end-=1
        return water