class Solution {
public:
    bool validPalindrome(string s) {
        int a = 0;
        int b = s.size() - 1;
        int count1 = 0, count2 = 0;

        while(a<b)
        {
            if(s[a]==s[b])
            {
                //increment the starting pointer and decrement the ending pointer if both the characters match
                a++;
                b--;
            }
            else
            {
                //incrementing the count1 variable if a character doesn't match
                count1++;
                //skip 1 character from the starting
                a++;
            }
            //breaking the loop if count1 is greater than 1, since only 1 char can skipped/deleted
            if(count1>1)
                break;
        }

        //re-initializing the pointers
        a = 0;
        b = s.size() - 1;

        while(a<b)
        {
            if(s[a]==s[b])
            {
                //increment the starting pointer and decrement the ending pointer if both the characters match
                a++;
                b--;
            }
            else
            {
                //incrementing the count2 variable if a character doesn't match
                count2++;
                //skip 1 character from the ending
                b--;
            }
             //breaking the loop if count2 is greater than 1, since only 1 char can skipped/deleted
            if(count2>1)
                break;
        }

        //0-count implies that the string is a palindrome
        if(count1 == 0 || count2 == 0)
            return true;
        //at most 1 character can be skipped/deleted
        if(count1 == 1 || count2 == 1)
            return true;

        return false;
    }
};

/*
   TC: O(N)
   SC: O(1)
*/
