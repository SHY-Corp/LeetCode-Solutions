class Solution {
    /**CLimbing Stairs leetcode java problem
        You are climbing a stair case. It takes n steps to reach to the top.
        Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
     */
    public int climbStairs(int n) {
        //Checks if there is only one stair in which case there is only one way to climb the stair
        if (n == 1) return 1;
        //Checks if there is only two stairs in which case there are only two ways to climb the stair
        if (n == 2) return 2;
        //initialize varaible first to be 1
        int first = 1;
        //initialize varaible second to be 2
        int second = 2;
        //initialize varaible res to be 0
        int res = 0;
        //while the number of stairs is greater than 2 run the loop
        while (n > 2) {
            //set res to the sum of first and second
            res = first + second;
            //set first to second
            first = second;
            //set second to res
            second = res;
            //decrement n;
            --n;
        }
        //return rest
        return res;
    }
}