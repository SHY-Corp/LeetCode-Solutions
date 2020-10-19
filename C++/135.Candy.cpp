/**
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?

## Example 1:
Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

## Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.

 * ref: https://leetcode.com/problems/candy/
 */
#define _max(a, b) a > b ? a : b
class Solution {
public:
    int candy(vector<int>& g) {
        size_t n = g.size();
        vector<int> c (n, 1);
        bool updated = false;
        int j = 1;
        int sum = 0;
        for (int i = 0; i < n - 1; i++){
            //check right left neighbor
            if(g[j + i] > g[i]){
                c[j + i] = c[i] + 1;
                //updated = false;
            }
        }
        for (int i = n - 2; i >=0; i--){
            //check greater than right neighbor
            if(g[i] > g[i + 1]){
                //c[i]++;
                c[i] = _max(c[i], c[i + 1] + 1);
                updated = false;
            }
        }
        for (int i = 0; i < n; i++)
            sum += c[i];
        return sum;
    }
};
