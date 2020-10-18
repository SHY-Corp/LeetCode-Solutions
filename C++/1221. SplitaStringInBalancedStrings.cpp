//Balanced strings are those who have equal quantity of 'L' and 'R' characters.
//Given a balanced string s split it in the maximum amount of balanced strings.
//Return the maximum amount of splitted balanced strings.

class Solution {
public:
   int balancedStringSplit(string s) {
        int count = 0,countSubStr = 0;
        for(char c : s){
            if(c == 'R')
                count++;
            else
                count--;
            if(count == 0){
                countSubStr++;
                count = 0;
            }
        }
        return countSubStr;
    }
};
