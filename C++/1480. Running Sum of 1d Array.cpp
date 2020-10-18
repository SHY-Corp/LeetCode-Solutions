class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> b;
        long int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            b.push_back(sum);
        }
        return b;
    }
};
