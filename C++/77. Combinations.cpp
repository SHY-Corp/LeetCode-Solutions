/*
 *  Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 *  You may return the answer in any order.
 *
 *
 *
 *  Example 1:
 *
 *  Input: n = 4, k = 2
 *  Output:
 *  [
 *    [2,4],
 *    [3,4],
 *    [2,3],
 *    [1,2],
 *    [1,3],
 *    [1,4],
 *  ]
 *
 *  Example 2:
 *
 *  Input: n = 1, k = 1
 *  Output: [[1]]
 *
 *
 *  
 *  Constraints:
 *
 *  1 <= n <= 20
 *  1 <= k <= n
 *
 *
 *
 */
 
 // ---------------------------------Solution Explanation------------------------------------
 
 /*
  * In this, we will be using recursion to find all the possible combination.
  * In the function 'findAllCombinations', initially, for loop will be started with 1 and then, 
  * In each iteration, the current 'element' value will be inserted and then
  * findAllCombincations function will be called by passing the incremented value of "element".
  * The value will be inserted until size of the 1D array becomes equal to 'k'. 
  * After insertion of 1D array into the solution, the value of 1D array will be popped out and loop will be called for the next incremented value.
  * The recursion will stop only when all the elements have been inserted in the 2D vector. 
  */
  
  class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        findAllCombinations(1, n, k, {}, ans);    
        return ans;
    }
    
   void findAllCombinations(int element, int n, int k, vector<int> result, vector<vector<int>> &ans) {
       
       if (result.size() == k) {
            ans.push_back(result);
            return;
       }
       
       for(int i=element; i<=n; i++) {
           result.push_back(i);
           findAllCombinations(i+1, n, k, result, ans);
           result.pop_back();
       }
   }
};
 
