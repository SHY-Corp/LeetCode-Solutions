/*

Problem : Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that 
the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container 
contains the most water.

Approach : 
    Initially we consider the area constituting the exterior most lines. Now, to maximize the area, we need to consider the area between the lines of 
    larger lengths. If we try to move the pointer at the longer line inwards, we won't gain any increase in area, since it is limited by the shorter line.
    But moving the shorter line's pointer could turn out to be beneficial, as per the same argument, despite the reduction in the width. This is done since 
    a relatively longer line obtained by moving the shorter line's pointer might overcome the reduction in area caused by the width reduction.
*/

public class Solution {
    public int maxArea(int[] height) {
        int maxarea = 0, l = 0, r = height.length - 1;
        while (l < r) {
            maxarea = Math.max(maxarea, Math.min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
}

