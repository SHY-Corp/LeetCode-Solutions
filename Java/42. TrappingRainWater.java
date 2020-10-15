class Solution {
    /*
        42. Trapping Rain Water

        Given n non-negative integers representing an elevation map where the width of each bar is 1, 
        compute how much water it is able to trap after raining.

        Example:
        Input: [0,1,0,2,1,0,1,3,2,1,2,1]
        Output: 6
    */

    public int trap(int[] heights) {
        int water = 0;
        int startMax = 0, endMax = 0;
        int start = 0, end = heights.length - 1;

        while(start < end) {
            if(heights[start] < heights[end]) {
                if(heights[start] > startMax) {
                    startMax = heights[start];
                } else {
                    water += startMax - heights[start];
                    start++;
                }
            }
            else {
                if(heights[end] > endMax) {
                    endMax = heights[end];
                } else {
                    water += endMax - heights[end];
                    end--;
                }
            }
        }

        return water;
    }
}