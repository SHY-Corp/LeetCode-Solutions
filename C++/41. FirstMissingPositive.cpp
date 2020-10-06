class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //Base case
        if(nums.size() == 0) return 1;
        
        // Goal: To put each number in its right index. If the number > nums.size(), leave it be.
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) 
                swap(nums[i], nums[nums[i]-1]);
        }
        
        //Finally, identify the smallest number that is out of place.
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1) return i+1;
        }
        return nums.size() + 1;
    }
};