/**
 * Solution to Number of Good Pairs in CPP
 *
 * author: ITES7321
 * ref:https://leetcode.com/problems/number-of-good-pairs/
 */

class Solution {
public:
  int numIdenticalPairs(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    unordered_map<int, int> mp;
    int num_pairs = 0;
      
    for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
    for(auto x : mp) num_pairs+= x.second != 1 ? (int)(x.second * (x.second - 1) / 2) : 0;
      
    return num_pairs;
  }
};