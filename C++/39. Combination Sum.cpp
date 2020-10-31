/*

    Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

    The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

    It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

    Example 1:
        Input: candidates = [2,3,6,7], target = 7
        Output: [[2,2,3],[7]]
        Explanation:
            2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
            7 is a candidate, and 7 = 7.
            These are the only two combinations.

    Example 2:
        Input: candidates = [2,3,5], target = 8
        Output: [[2,2,2,2],[2,3,3],[3,5]]

    Example 3:
        Input: candidates = [2], target = 1
        Output: []
    
    Example 4:
        Input: candidates = [1], target = 1
        Output: [[1]]
*/
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

vector<int> result;
class Solution {
public:
    void targetsum(vector< vector<int> > &ans,vector<int> &candidates,int target,int j=0){
        int n=candidates.size();
        if(n==0) {
            ans.push_back(result);
            return;
        }
        if(target==0) {
            ans.push_back(result);
            return;
        }
        for(int i=j;i<n;i++){
            int temp=candidates[i];
            if((target-temp)>=0){
                result.push_back(temp);
                targetsum(ans,candidates,(target-temp),i);
                result.pop_back();
            }
            else return;
        }
    }
    vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector< vector<int> > ans;
        targetsum(ans,candidates,target);
        return ans;
    }
};