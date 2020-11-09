// problem - 1647. Minimum Deletions to Make Character Frequencies Unique

/*
    A string s is called good if there are no two different characters in s that have
    the same frequency.

    Given a string s, return the minimum number of characters you need to delete to make s good.

    The frequency of a character in a string is the number of times it appears in the string. 
    For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.
*/

#include <unordered_map>
class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        // base case n == 0 or n == 1
        if(n < 2) return 0;
        
        // creating a table to store frequency of characters
        unordered_map<char, int> chars;
        for(int i=0; i<n; i++) {
            chars[s[i]]++;
        }
        
        // an array to store number of similar frequencies
        vector<int> freq(n+1, 0);
        for(auto x: chars) {
            freq[x.second]++;
        }
        
        int deletions = 0;
        bool unique = false;
        while(!unique) {
            unique = true;
           for(int i=0; i<n; i++) {
                if(i != 0 && freq[i] > 1) {
                    int temp = (freq[i] - 1);
                    freq[i] = 1;
                    freq[i-1] += temp;
                    deletions += temp;
                    unique = false;
                }
            } 
        }
       
        return deletions;
    }
};

// Time Complexity = O(n^2) Quadratic Time
// Space Complexity = O(n) Linear Time