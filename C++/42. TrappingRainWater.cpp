
/***
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

Solution: Dynamic Programming
***/

class Solution {
public:
    int trap(vector<int>& height) {
        // detect edge case 
        if (height.size() < 2) return 0;
        
        int n = height.size();
        int left_max[n];
        int right_max[n];
        
        left_max[0] = height[0];
        for (int i = 1; i < n; i ++) {
            left_max[i] = max(left_max[i-1], height[i]);
        }
        right_max[n-1] = height[n-1];
        for (int i = n-2; i >= 0 ; i --) {
            right_max[i] = max(right_max[i+1], height[i]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        
        return ans;
    }
};