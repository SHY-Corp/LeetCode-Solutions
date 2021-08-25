/* The following code contains the Class which provides a public method to 
check if two string are anagrams of each other. 
Method name : isAnagram
@param, two Strings s and t.
Conditions provided, strings contain only lowercase alphabets
*/

// header for string
#include <string>

using std::string;
class Solution

{
public:
    bool isAnagram(string s, string t)
    {
        /*Return false if length of the two strings are unequal as they cannot
        form anagrams */
        if (s.length() != t.length())
            return false;
        int n = s.length();
        int counts[26] = {0};
        /*For every alphabet in string s and string t, the alphabet in 
        string s is cancelled by the same alphabet in string t. */
        for (int i = 0; i < n; i++)
        {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        /*If all the alphabets in string s is cancelled by string t, 
        we will return true, because it is an anagram, else we return 
        false */
        for (int i = 0; i < 26; i++)
            if (counts[i])
                return false;
        return true;
    }
};