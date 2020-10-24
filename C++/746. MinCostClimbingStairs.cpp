/*
Title: 746. Min Cost Climbing Stairs

On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

*/



class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int i;
        int n = cost.size();
        i = n - 3;
        while(i >= 0){
            cost[i] += min(cost[i+1], cost[i+2]);
            i--;
        }
        
        
        return min(cost[0], cost[1]);
        
    }
};
