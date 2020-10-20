// Problem-22 Letter Combinations of a Phone Number

//Given a string containing digits from 2-9 inclusive, return all possible 
//letter combinations that the number could represent. Return the answer in any order.

//A mapping of digit to letters (just like on the telephone buttons) is given below. 
//Note that 1 does not map to any letters.
/*
 1    2    3
     abc  def
 4    5    6
gef  jkl  mno
 7    8    9
pgrs tuv wxyz
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        string map[]= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> ans;
        if(digits== "")
            return ans;
        
        ans.push_back("");
        
        int n= digits.size();
        for(int i=0; i<n; i++){
            int dig= digits[i]- '0';
            
            vector<string> temp;
            int m= map[dig].size();
            for(int j=0; j<m; j++){
                for(int k=0; k<ans.size(); k++){
                    string elem= ans[k]+ map[dig][j];
                    temp.push_back(elem);
                }
            }
            
            ans.clear();
            ans= temp;
        }
        
        return ans;
        
    }
};