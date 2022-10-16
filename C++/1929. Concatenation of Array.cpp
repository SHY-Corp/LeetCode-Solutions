/*
Submitted by vipul kumar singh
concatenation means combining/ joining of two  letters , string or etc
question link :: https://leetcode.com/problems/concatenation-of-array/
*/
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        int size = nums.size(); // simply to get the length/size of the vector (int type )
        
        for (auto i = 0 ; i <size  ; i++) //  for loop for traversal 
        {
            nums.push_back(nums.at(i)); // insertion of data at particular index from the last or end 
        }
        
        return nums;
        
    }
};
