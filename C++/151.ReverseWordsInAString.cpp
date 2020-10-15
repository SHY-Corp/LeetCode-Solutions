/* Given an input string s, reverse the order of the words.
   Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. 
   Do not include any extra spaces.
   
   Return a string of the words in reverse order concatenated by a single space.
*/

/* 
   Example :
   Input: s = "the sky is blue"
   Output: "blue is sky the"
   
*/


class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int j = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ' ')
            {
                if(i > j)
                    result = s.substr(j,i-j) + " " + result;
                    j = i+1;
            }
            else if(i == s.size()-1)
                result = s.substr(j,s.size()-j) + " " + result;
        }
        s=result.substr(0,result.size()-1);
        return s;
    }
};
