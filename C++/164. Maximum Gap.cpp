// problem - 164. Maximum Gap

/*
    Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
    Return 0 if the array contains less than 2 elements.
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        // to handle edge case
        if(n < 2) return 0;
        
        // sorting the nums array and looping through to get maximum difference
        sort(nums.begin(), nums.end());
        int answer = 0;
        for(int i=1; i<n; i++) {
            answer = max(answer, nums[i]-nums[i-1]);
        }
        
        return answer;
    }
};

// Time Complexity - O(nlogn) Logrithmic Time (sorting function takes O(nlogn))
// Space Complexity - O(1) Constant Time