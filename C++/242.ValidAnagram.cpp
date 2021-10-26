/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        //base cases
        if (s.size()!=t.size())
            return false;
        if (s.empty() && t.empty()) return true;

    /*  This was a naive approach, therefore commented for now.  There is a better approach keeping the follow up question in mind.
        sort(begin(s), end(s));
        sort(begin(t), end(t));

          return s==t ; */

        map <char, int> m;

        for(char c: s)  //alt: for(int i=0; i<s.length(); i++), if map<int, int> m; m[s[i]]++, m[t[i]]--
            m[c]++;

        for(char c: t)
            m[c]--;

        for(auto it = m.begin(); it!=m.end(); it++)
        {
            if(it->second != 0)    //first(key): can't change, second(value): CAN change
                return false;      //if the count isn't 0, it means the character is either extra or less.
        }

     return true;
    }
};
