class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
        Our goal is to add every element of nums in its correct place and then find the smallest number that's not present in its place.
        eg. nums = [2, 1, 4]
        Explanation: 
        According to the following algorithm, we check for each element of nums:
                2 -> 1st place in the array. Therefore, we swap 2 with 1. 
                Update: nums = [1, 2, 4]
                2 -> 2nd place in the array
                4 -> 4 > nums.size() (i.e. 3). Therefore, we skip.
        Now, we traverse the array again and return the smallest element that is not in its correct place.
        */
        int flag =1;
        //Base case
        if(nums.size() == 0) return 1;
        
        // Goal: To put each number in its right index. If the number > nums.size(), leave it be.
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) 
                swap(nums[i], nums[nums[i]-1]);
        }
        
        //Finally, identify the smallest number that is out of place.
        for(int i = 0; i < nums.size(); i++){
            flag = 0;
            if(nums[i] != i+1) return i+1;
        }
        return nums.size() + 1;
    }
};
