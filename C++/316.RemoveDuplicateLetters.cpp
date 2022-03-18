class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0), seen(26,0);
        string unique = "";

        //storing frequency of each character
        for(auto i: s)
        {
            freq[i-'a']++;
        }

        //iterating to check if the character is present in the given string, if not, adding it to the resultant
        //string by maintaining a lexicographical order
        for(auto i: s)
        {
            //decrease the count of current character
            freq[i-'a']--;

            //if this character is not in the output string, we will check for other parameters inside the loop
            if(seen[i-'a']==0)  //or !seen[i-'a']
            {
                //if the last character in the result string is greater than the current character, and its
                //frequency is also greater than 0
                while(unique.size()>0 && unique.back()>i && freq[unique.back()-'a']>0)
                {
                    //mark the last character as seen
                    seen[unique.back() - 'a'] = 0;
                    unique.pop_back();
                }

                //add the current character to the resultant string and mark it as seen
                unique += i;
                seen[i-'a'] = 1;
            }
        }
        return unique;
    }
};


