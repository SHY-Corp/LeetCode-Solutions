/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.
21 is read off as one 2, then one 1 or 1211.
Given an integer n, generate the nth sequence.
Note: The sequence of integers will be represented as a string.
Example:
if n = 2,
the sequence is 11.
*/

class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for(int i=1;i<n;i++){
            vector<pair<int,int> > num;
            num.push_back(make_pair(s[0]-'0',1));
            int x=0;
            for(int j=1;j<s.length();j++){
                if(s[j-1]==s[j])
                    num[x].second++;
                else{
                    x++;
                    num.push_back(make_pair(s[j]-'0',1));
                }
            }
            s="";
            for(int j=0;j<num.size();j++){
                s.push_back(num[j].second + '0');
                s.push_back(num[j].first + '0');
            }
        }
        return s;
    }
};
