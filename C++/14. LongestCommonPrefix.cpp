class Solution {
public:
    string longestCommonPrefix(vector<string>& strings) {
        if (strings.empty()) // Empty vector
        {
            return ""; //the prefix is empty string
        }

        for (int i = 0; i < strings[0].length(); ++i) 
        { 
            //for the first string in vector
            
            for (const auto& s : strings) 
            { 
                //check all the other strings
                
                if (i >= s.length() || s[i] != strings[0][i])
                //if the length of the string is equal to i or the strings have different character
                { 
                    //return the substring prefix
                    return strings[0].substr(0, i); 
                }
            }
        }
        return strings[0];
        //if the loop finishes, then the first string is the prefix.
    }
};