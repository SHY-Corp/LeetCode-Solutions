// Problem - 44. Wildcard Matching

/*
Problem statement -
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/

/*
Constraints -
1. 0 <= s.length, p.length <= 2000
2. s contains only lowercase English letters.
3. p contains only lowercase English letters, '?' or '*'.
*/

/*
Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Example 4:
Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

Example 5:
Input: s = "acdcb", p = "a*c?b"
Output: false
*/

//Solution
/*
Idea -
The reason that the iterative solution is much faster for this case is we only need to save (and deal with) the positions (iStar for s, jStar for p) of the last "" we met.
We only need to do traceback using iStar and jStar and all the previous "" can be ignored since the last "" will cover all the traceback cases for the previous "".
What we need to do are
1. if the current p character is '' (i.e. p[j]==''), then we update iStar and jStar with the cureent i and j values. iStar/jStar will be used for traceback. 
Also we do --i to start the depth first search with the case that '*' represents a null string.
2. if p[j]!='', then we check if mismatch occurs (i.e. p[j]!=s[i] and p[j]!='?'), if so we check if we met a '' before (iStar>=0), if not, then we return false since no match can achieve.
Otherwise, we traceback to the positions at which the last '*' happens and do the next possible dfs search (i.e. i = iStar++; j = jStar; remember to update iStar too to save the i position to try in the next traceback).
3. The loop will quit when we reach the end of s. At last, we need to skip all the '*' in p to see if we can reach the end of p. 
if so, match, otherwise mismatch
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int  slen = s.size(), plen = p.size(), i, j, iStar=-1, jStar=-1;

        for(i=0,j=0 ; i<slen; ++i, ++j)
        {
            if(p[j]=='*')
            { //meet a new '*', update traceback i/j info
                iStar = i;
                jStar = j;
                --i;
            }
            else
            {
                if(p[j]!=s[i] && p[j]!='?')
                {  // mismatch happens
                    if(iStar >=0)
                    { // met a '*' before, then do traceback
                        i = iStar++;
                        j = jStar;
                    }
                    else return false; // otherwise fail
                }
            }
        }
        while(p[j]=='*') ++j;
        return j==plen;
    }
};
