/*
Problem 1023 - CammelCase Matching

A query word matches a given pattern if we can insert lowercase letters to the
pattern word so that it equals the query. (We may insert each character at any
position, and may insert 0 characters.)
Given a list of queries, and a pattern, return an answer list of booleans, where
answer[i] is true if and only if queries[i] matches the pattern.
*/

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> answer;
        for(int i=0; i<queries.size(); i++){
            answer.push_back(matchesPattern(pattern, queries.at(i)));   //for each word in queries: check if it matches pattern
        }
        return answer;  //answer vector
    }
    
    bool matchesPattern(string pattern, string word){
        int i = 0;
        for(int j=0; j<word.size(); j++){
            if(word[j] <= 90 && word[j] >=45){  //if found uppercase in word
                if(word[j] == pattern[i] && i < pattern.size()){    //check if it is the next pattern char to be found
                    i++;
                }else{
                    return false;   //if found uppercase char and it isn't the next pattern char to be found: return false
                }
            }else{  //if found lowercase
                if(word[j] == pattern[i] && i < pattern.size()){ //check if it is the next pattern char to be found
                    i++;
                }
            }
        }
        if(i == pattern.size()) return true;    //if all pattern characters were found: return true
        else return false;  //otherwise: return false
    }
};