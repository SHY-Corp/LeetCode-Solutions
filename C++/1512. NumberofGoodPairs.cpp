//Given an array of integers nums.
//A pair (i,j) is called good if nums[i] == nums[j] and i < j.
//Return the number of good pairs.

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
    int answer = 0;
    map<int, int> freq;
        for(int n : nums) {
            freq[n]++;
            if(freq[n] >= 2)
            answer+= freq[n] - 1;
        }
    return answer;
    }
};
