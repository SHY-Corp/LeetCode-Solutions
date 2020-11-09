// problem - 1646. Get Maximum in Generated Array

/*
    You are given an integer n. An array nums of length n + 1 is generated in the following way:
        nums[0] = 0
        nums[1] = 1
        nums[2 * i] = nums[i] when 2 <= 2 * i <= n
        nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n

    Return the maximum integer in the array nums​​​.
*/

class Solution {
public:
    int getMaximumGenerated(int n) {
        // base case
        if(n == 0) return 0;

        // using simulation to solve 
        vector<int> nums(n+1);
        // given
        nums[0] = 0;
        nums[1] = 1;
        
        int answer = 1;        
        for(int i=2; i<=n; i++) {
            if(i&1) {
                int j = (i - 1) >> 1; // (i-1)/2
                nums[i] = nums[j] + nums[j+1];
            } else {
                int j = i >> 1; // i/2
                nums[i] = nums[j];
            }
            
            answer = max(answer, nums[i]);
        }
        
        return answer;
    }
};

// Time Complexity = O(n) Linear Time
// Space Complexity = O(n) Linear Time