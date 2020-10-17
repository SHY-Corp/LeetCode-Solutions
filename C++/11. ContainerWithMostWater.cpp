/*

Problem : Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Approach : 
	Start with pointer left=0 and pointer right=length-1
	The max water is limited by the pointer with smaller height
	when moving a pointer, the width of the area decrease
	If we move the pointer with higher height, we will never get a greater area, the max height will be at most the one of the pointer with smaller height.
	So we need to move the pointer with smaller height to have a chance to get higher height at the next

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ptr1 = 0, ptr2 = height.size() - 1, maxi = 0;
        while(ptr1 < ptr2) {
            maxi = max(maxi, min(height[ptr1], height[ptr2]) * (ptr2 - ptr1));
            if(height[ptr1] < height[ptr2]) ptr1++;
            else ptr2--;
        }
        return maxi;
    }
};
