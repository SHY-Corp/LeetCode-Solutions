/*
Problem 953 - Verifying an Alien Dictionary

In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.
*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> alphabet;
        // Fill map object with order information to optimize access to it
        for(int i=0; i<order.size(); i++) {
            alphabet[order[i]] = i;
        }
        // For each word
        for(int i=0; i<words.size(); i++) {
            // Compare it with the following words
            for(int k=i+1; k<words.size(); k++) {
                // Find out if the first different and corresponding characters in each word are sorted lexicographically
                for(int j=0; j<words[i].size(); j++) {
                    if(words[k].size() >= (j+1)) {
                        // If different corresponding characters are not sorted accordingly: return false
                        if(alphabet[words[i][j]] > alphabet[words[k][j]]) {
                            return false;
                        }
                        // If different corresponding characters are sorted accordingly: break and continue comparisons with other words
                        else if(alphabet[words[i][j]] < alphabet[words[k][j]]){
                            break;
                        }
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};