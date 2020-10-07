/* Question:
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.   */

//Solution
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs==null || strs.length==0) return "";
        String prev=strs[0]; int i=1;
        while(i< strs.length){
            while(strs[i].indexOf(prev)!=0)
                prev=prev.substring(0,prev.length()-1);
            i++;
        }
        return prev;
    }
}
