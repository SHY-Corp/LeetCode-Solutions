// problem - 394. Decode String

/*
    Given an encoded string, return its decoded string.

    The encoding rule is: k[encoded_string], where the encoded_string inside 
    the square brackets is being repeated exactly k times. Note that k is guaranteed 
    to be a positive integer.

    You may assume that the input string is always valid; No extra white spaces, 
    square brackets are well-formed, etc.

    Furthermore, you may assume that the original data does not contain any digits and 
    that digits are only for those repeat numbers, k. For example, 
    there won't be input like 3a or 2[4].
*/

#include <stack>
class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        st.push(make_pair("", 1));
        
        // to store number
        string num = "";
        for(int i=0; i<s.length(); i++) {
            // if S[i] is a digit from 0 to 9
            if(s[i] >= 48 && s[i] <= 57) {
                num += s[i];
            } else if(s[i] == '[') {
                // pushing the number along with empty string
                st.push(make_pair("", stoi(num, nullptr, 10)));
                num = "";
            } else if(s[i] == ']') {
                // top most element in the stack
                pair<string, int> reg = st.top();
                st.pop();
                // second top most element in the stack
                pair<string, int> temp = st.top();
                st.pop();
                for(int i=0; i<reg.second; i++) {
                    // second top += first top
                    temp.first += reg.first;
                }
                st.push(temp);
            }
            // any other chars, (letters)  
            else {
                pair<string, int> temp = st.top();
                st.pop();
                temp.first += s[i];
                st.push(temp);
            }
        }
        
        return st.top().first;
    }
};

// Time Complexity = O(n * m) 
// Space Complexity = O(n) [where n is the length of the given string and 
//                                m is max number in the given string]