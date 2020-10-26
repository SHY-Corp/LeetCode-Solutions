/*
    Problem Statement :
        #70.
            You are climbing a stair case. It takes n steps to reach to the top.
            Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


    Constraints:
            1 <= n <= 45

    Approach:
            The constraints give us a clue of an existing exponential solution, but as always exponential solutions are
            dumped. Hence we use the common Dynamic Programming approach to solve the problem; The stairs are considered
            as an array, where the value denotes the count of steps required assuming the person is allowed 1 or 2 steps.

*/
class Solution {
public:
    int climbStairs(int n) {
        int step[n+1];
        memset(step, 0 , sizeof(step));
        step[0] = 1;
        for(int i = 1; i< n+1; i++){
            if(i>=2)
                 step[i] = step[i-1] + step[i-2];
            else
                step[i] = step[i-1];           // If the there are less than 2 steps, the subtraction gives a negative array index
                                               // Hence we use this else condition
        }
        return step[n];
    }
};
