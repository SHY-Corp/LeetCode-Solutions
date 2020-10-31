/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, 
who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
*/

class Solution {
public:
    static bool sortcol(const vector<int> &v1,const vector<int> &v2) {
        return v1[0] > v2[0];
    }
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res(nums.size());
        
        if(nums.size() == 0)
            return res;
        else if(nums.size() == 1) {
            res[0] = "Gold Medal";
            return res;
        }
        else if(nums.size() == 2) {
            if(nums[0] > nums[1]) {
                res[0] = "Gold Medal";
                res[1] = "Silver Medal";
            }
            else {
                res[0] = "Silver Medal";
                res[1] = "Gold Medal";
            }
            return res;
        }
        
        vector<vector<int>> temp(nums.size());
        
        for(int i=0; i<nums.size(); i++) {
            vector<int> v(2);
            v[0] = nums[i];
            v[1] = i;
            temp[i] = v;
        }
        
        sort(temp.begin(), temp.end(), sortcol);
        for(int i=3; i<nums.size(); i++) {
            string pos = to_string(i+1);
            res[temp[i][1]] = pos;
        }

        res[temp[0][1]] = "Gold Medal";
        res[temp[1][1]] = "Silver Medal";
        res[temp[2][1]] = "Bronze Medal";
        return res;
        
    }
};