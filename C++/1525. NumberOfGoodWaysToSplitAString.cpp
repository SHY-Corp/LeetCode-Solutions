/*
You are given a string s.
A split is called good if you can split s into 2 non-empty strings p and q where its concatenation is equal to s and the number of distinct letters in p and q are the same.

Return the number of good splits you can make in s.
*/

class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        int ans=0;
        // Map for having freq of each char in set2
        unordered_map<char, int> freq;
        
        // Total distinct elements in string - keeps count for split 2
        unordered_set<char> s2;
        for(int i=0;i<n;i++){
            s2.insert(s[i]);
            freq[s[i]]++;
        }
        int distElt = s2.size();
        
        int dist2=0;
        // Set for having count of distinct elements in 1st split - keeps running count
        unordered_set<char> s1;
        for(int i=0;i<n;i++){
            s1.insert(s[i]);
            dist2 = s1.size();
            freq[s[i]]--;
            if(freq[s[i]]==0) distElt--;
            if(dist2 == distElt) ans++;
        }
        return ans;
    }
};