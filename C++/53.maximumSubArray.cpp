class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximumSum = nums[0];
        int currentSum = nums[0];
        int i;
        for(i=1;i<nums.size();i++){
            currentSum = max(nums[i] + currentSum, nums[i]);
            maximumSum = max(maximumSum, currentSum);
        }
        return maximumSum;
    }
};