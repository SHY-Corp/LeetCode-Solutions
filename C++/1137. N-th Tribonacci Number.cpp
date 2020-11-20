// problem - 1137. N-th Tribonacci Number

/*
    The Tribonacci sequence Tn is defined as follows: 
        T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

    Given n, return the value of Tn.
*/

class Solution {
    // memoization
    vector<int> rec = {0,1,1};
public:
    int tribonacci(int n) {
        // base case
        if(n < rec.size()) return rec[n];
        // memoizing
        rec.push_back(tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3));
        
        // final output
        return rec[n];
    }
};

// Time Complexity = O(n)
// Space Complexity = O(n) [where n is input to tribonacci()]