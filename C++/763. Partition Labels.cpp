/*
    A string S of lowercase English letters is given. We want to partition this string into as many parts as 
    possible so that each letter appears in at most one part, and return a list of integers representing the 
    size of these parts.

    Example 1:
        Input: S = "ababcbacadefegdehijhklij"
        Output: [9,7,8]
        Explanation:
            The partition is "ababcbaca", "defegde", "hijhklij".
            This is a partition so that each letter appears in at most one part.
            A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

        Note:

           * S will have length in range [1, 500].
           * S will consist of lowercase English letters ('a' to 'z') only.
   
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector< pair<int, int> > pairs(26, {-1, -1});

        for(int i=0;i<S.size();i++){
            int c=S[i]-'a';
            if(pairs[c].first==-1) {
                pairs[c].first=i;
                pairs[c].second=i;
            }else{
                pairs[c].first=i;
            }
        }

        sort(pairs.begin(), pairs.end());
        vector<int> ans;
        int start=0,end=S.size();
        for(;start<S.size();){
            for(int i=0;i<26;i++){
                if(pairs[i].second==-1) continue;
                if(pairs[i].second==start){
                    end=pairs[i].first;
                }
                else if(end>pairs[i].second){
                    end=max(pairs[i].first, end);
                }
            }
            ans.push_back(end-start+1);
            start=end+1;
        }
        return ans;
    }
};