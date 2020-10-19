/*
Aim : Sort the char of a string acc to its freq , if freq of 2 char is same thn acc to the lexographical order

Soln: count and store all the occ of all char in a array
      sort it using the inbuilt sort func
      
      here [&] is a lamda func
      lamda func are a func that are trival and not worth declaring seperetly.
      
      sort function can also be called as
        sort(s.begin(), s.end(), fun);
        
        bool fun(char &a, char &b){
            --same as below
        }
*/
class Solution {
public:
    string frequencySort(string s) {
        
        int freq[256] = {0};
        
        for(char c : s)
            freq[c]++;
        
        sort(s.begin(), s.end(), [&](char &a, char &b){
            return freq[a] > freq[b] || freq[a] == freq[b] && a < b; 
        });
        
        return s;
    }
};
