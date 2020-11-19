// problem - 46. Permutations

/*
    Given an array nums of distinct integers, return all the possible permutations.
    You can return the answer in any order.
*/

class Solution {
    // using global variable the store final answer
    vector<vector<int>> answer;
public:
    // using backtracking
    void backtrack(vector<int>& nums, vector<bool>& track, vector<int>& permutation) {
        // at leaf node
        if(nums.size() == permutation.size()) answer.push_back(permutation);
        else {
            for(int i=0; i<track.size(); i++) {
                if(track[i]) {
                    permutation.push_back(nums[i]);
                    track[i] = false;
                    
                    backtrack(nums, track, permutation);
                    
                    // backtracking
                    track[i] = true;
                    permutation.pop_back();
                }
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        // to store one permutation at a time
        vector<int> permutation;
        // to track the used nums
        vector<bool> track(n, true);
        
        backtrack(nums, track, permutation);
        
        return answer;
    }
};

// Time Complexity = O(n!) [where n is size of the nums vector]
// Space Complexity = O(n!*n) = O(n!)
