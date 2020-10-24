/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].


*/

#include <vector>
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int start = -1;
        int end = -1;
        vector<int> range;
        bool flag = false;

        if (nums.size() == 0){

            range = {-1, -1 };
            return range;

        }

        for (size_t i = 0; i < nums.size(); ++i){

            if (nums[i] == target) {

                start = i;
                break;

            }


        }

        for (int i = static_cast<int>(nums.size()) - 1; i >= 0; --i){

            if (nums[i] == target) {

                end = i;
                break;

            }


        }

        range.push_back(start);
        range.push_back(end);
        return range;

    }
};
