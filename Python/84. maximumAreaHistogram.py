# Function maximumAreaHistogram returns the max area of the rectangle in the histogram. 
# Each bar has 1 width, and the input array contains n non-negative integers.

class Solution:
    def maximumAreaHistogram(self, heights:List[int]) -> int:
        """
            Find the largest area of rectangle in the histogram
            :param heights: List[int] a list of integer numbers
            :return: Value of the maximum area of the rectangle
        """

        ans = 0
        stack = [-1] # the stack is used to stored the histogram in the ascending order
        heights.append(0) # the reason why we need to append 0 to the last is because otherwise the last histogram will not be calculated

        # Before adding a new building to the stack, we would pop out all the buildings higher than current one. 
        # The we would calculate the area  by setting the current building as the right boundary and the stack top building as the left boundary
        # The reason why it works is because the stack is maintain in ascending order, so we could ensure that the earlier building is shorter than the latter one. 
        for i in range(len(heights)):
            while heights[i] < heights[stack[-1]]:
                h = heights[stack.pop()]
                w = i - stack[-1] - 1
                ans = max(ans, h * w)
            stack.append(i) # since we pop out all the buildings taller than the current one, then the current one is the highest.
        return ans
