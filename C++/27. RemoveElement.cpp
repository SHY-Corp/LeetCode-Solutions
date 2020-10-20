/* Program name :- Remove Element.cpp
 this program will receive an array of integers, and a value. Count the number of integers in the array after deleting all elements whose value is val.
 
 For Example:
 
 Input: nums = [0,1,2,2,3,0,4,2], val = 2
 Output: 5, nums = [0,1,4,0,3]
 
 Explanation: 
 Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4. 
 Note that the order of those five elements can be arbitrary. It doesn't matter what values are set beyond the returned length

*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            if(nums[i]!=val)    
               v.push_back(nums[i]);
        }
        nums=v;
        return nums.size();
    }
};
