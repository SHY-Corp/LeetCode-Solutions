// problem - 47. Permutations II

/*
    Given a collection of numbers, nums, that might contain duplicates, 
    return all possible unique permutations in any order.
*/

class Solution {
    // using global variable the store final answer
    vector<vector<int>> answer;
public:
    // using backtracking
    void backtrack(vector<int>& nums, vector<bool>& track, vector<int>& permutation) {
        // at leaf node
        if(permutation.size() == nums.size()) answer.push_back(permutation);
        else {
          for(int i=0; i<track.size(); i++) {
              // to avoid duplicates
              if(i > 0 && track[i-1] && nums[i] == nums[i-1]) continue;
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
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        // to store one permutation at a time
        vector<int> permutation;
        // to track the used nums
        vector<bool> track(n, true);
        
        // sorting to avoid duplicates
        sort(nums.begin(), nums.end());
        backtrack(nums, track, permutation);
        
        return answer;
    }
};

// Time Complexity = O(n!*nlogn) = O(n!) [where n is size of the nums vector]
// Space Complexity = O(n!*n) = O(n!)