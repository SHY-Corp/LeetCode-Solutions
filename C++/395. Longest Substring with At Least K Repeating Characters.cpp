// problem - 395. Longest Substring with At Least K Repeating Characters

/*
    Given a string s and an integer k, return the length of the longest substring of s 
    such that the frequency of each character in this substring is greater than 
    or equal to k.
*/

#include <unordered_map>
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if(n < k) return 0;
        if(k == 1) return n;
        
        // tracking frequency of all characters in the string
        unordered_map<char, int> freq;
        for(char ch: s) freq[ch]++;
        
        // breaks if a character's frequency < k or l >= n
        int l = 0;
        while(l < n && freq[s[l]] >= k) l++;
        
        if(l >= n-1) return l;
        
        // recursively checking string till l
        int res1 = longestSubstring(s.substr(0, l), k);
        while(l < n && freq[s[l]] < k) l++;
        // recursively checking string after l
        int res2 = (l > n) ? 0 : longestSubstring(s.substr(l, n), k);
        
        return max(res1, res2);
    }
};

// Time Complexity = O(N)
// Space Complexity = O(N) [where N is length of the given string]