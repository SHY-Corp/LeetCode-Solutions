/* PROBLEM:   Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

APPROACH: impplemented two sum using two pointers strating from start and end of given vector

*/


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v;
        int l=numbers.size();
        for(int i=0,j=l-1;i<l,j>=0;){
            if(numbers[i]+numbers[j]==target){
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            else if(numbers[i]+numbers[j]>target) j--;
            else i++;
        }
        return {1};
    }
};
