/*
Problem 942 - DI String Match

A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:
s[i] == 'I' if perm[i] < perm[i + 1], and
s[i] == 'D' if perm[i] > perm[i + 1].
Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.
*/

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();   // length of the string
        int lowLimit = 0;   // minimum integer
        int upLimit = n;   // maximum integer
        vector<int> answer; // output array to store the original permutation
        for(int i=0; i<(n+1); i++) {
            // If the current char is 'I' append the current lower limit
            if(s[i] == 'I') {
                answer.push_back(lowLimit);
                lowLimit += 1;
            }
            // If the current char is 'D' append the current upper limit
            else {
                answer.push_back(upLimit);
                upLimit -= 1;
            }
        }
        return answer;
    }
};