//6. ZigZag Conversion

/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

For example,
	Input: s = "PAYPALISHIRING", numRows = 4
	Output: "PINALSIGYAHRPI"
*/


#include<vector>
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        bool down = false;
        int j = 0;
        vector<string>v(numRows);
        for(int i = 0; i < s.length(); i++) {
            v[j] += s[i];
            if(j == 0 || j == numRows-1) {
                down = !down;     
            }
            if(down) {
                j++;
            }
            else j--;
           
        }
        string res = "";
        for(int i = 0; i < v.size(); i++) {
            res += v[i];
        }
        return res;
    }
};