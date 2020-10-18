//Java Solution whose runtime beats 100% of all submissions for problem 1208 | Get Equal Substrings Within Budget
/*
You are given two strings s and t of the same length. You want to change s to t. Changing the i-th character of s to i-th character of t costs |s[i] - t[i]| that is, the absolute difference between the ASCII values of the characters.

You are also given an integer maxCost.

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of twith a cost less than or equal to maxCost.

If there is no substring from s that can be changed to its corresponding substring from t, return 0.

 

Example 1:

Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum length is 3.
Example 2:

Input: s = "abcd", t = "cdef", maxCost = 3
Output: 1
Explanation: Each character in s costs 2 to change to charactor in t, so the maximum length is 1.
Example 3:

Input: s = "abcd", t = "acde", maxCost = 0
Output: 1
Explanation: You can't make any change, so the maximum length is 1.
 

Constraints:

1 <= s.length, t.length <= 10^5
0 <= maxCost <= 10^6
s and t only contain lower case English letters.
*/

class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        if(maxCost == 0 && s.equals(t)) //corner case
            return s.length();
        int[] diff = new int[s.length()];
        for(int i=0; i<diff.length ; ++i){ //calculating absolute difference between characters as cost
            diff[i] = Math.abs(s.charAt(i) - t.charAt(i));
        }
        int currCost = 0;
	
	//sliding window technique
        int start=0, end=0, max=0;
	//end adds new cost and start deletes cost that don't comply to the constraints
        for(end = 0; end<diff.length ;++end){
            currCost += diff[end];
            while(currCost > maxCost && start<=end){ 
                currCost -= diff[start];
                ++start;
            }  
            max = Math.max(max, end-start+1); //max length is determined from every window
        }
        return max;
    }
}
