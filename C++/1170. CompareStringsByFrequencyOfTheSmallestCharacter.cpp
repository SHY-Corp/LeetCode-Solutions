/*
    Problem Statement:
    # 1170.
           Let's define a function f(s) over a non-empty string s, which calculates the frequency of the smallest character in s.
           For example, if s = "dcce" then f(s) = 2 because the smallest character is "c" and its frequency is 2.
           Now, given string arrays queries and words, return an integer array answer,
           where each answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words.

           Constraints:
            1 <= queries.length <= 2000
            1 <= words.length <= 2000
            1 <= queries[i].length, words[i].length <= 10
            queries[i][j], words[i][j] are English lowercase letters.


    Approach:
            The constraints allow us the use O(n^2) approach; To keep a modular approach to question we define a function
            calc_min which return the frequency of the smallest character for a given string. Then we compare each string
            from the queries vector to words vector. We count the words in vector for which the queries entry has smaller
            entry.
*/

class Solution {
public:
    int calc_min(string x){
        int ans;
        int count[256]={0};
        for(int i=0;i<x.length();i++){
            count[x[i]-'a']++;
        }
        for(int i=0;i<256;i++){
            if(count[i]>0)
            {ans= count[i];
            break;}
        }
        return ans;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> queries_small;
        vector<int> words_small;
       for(auto x: queries){
           queries_small.push_back(calc_min(x));
       }
        for(auto y: words){
            words_small.push_back(calc_min(y));
        }
        vector<int> ans;
        for(int i=0;i<queries_small.size();i++){
            int count=0;
            for(int j=0;j<words_small.size();j++){
                if(words_small[j]>queries_small[i])
                    ++count;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
