// problem - 709. To Lower Case

/*
    Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
*/

class Solution {
public:
    string toLowerCase(string& str) {
        for(int i=0; i<str.length(); i++) {
            // using ASCII values to find upper case and then adding 32
            // to convert into lower case
            if(str[i] > 64 && str[i] < 91) str[i] = (str[i] + 32);
        }
        
        return str;
    }
};

// Time Complexity = O(n) [n is the length of the given string]
// Space Complexity = O(1)