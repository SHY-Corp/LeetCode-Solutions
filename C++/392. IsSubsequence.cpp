/*Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not) */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i, j = 0;
        if (s.length() == 0)
            return true;
        char c = s[0];
        if (t.length() < s.length())
            return false;
        for (i = 0; i < t.length(); i++)
        {
            if (t[i] == c)
            {
                j++;//cout<<j;
                if (j == s.length())
                    return true;
                c = s[j];
            }
        }

        return false;
    }
};