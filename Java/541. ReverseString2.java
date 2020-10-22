/*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. 
If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, 
then reverse the first k characters and left the other as original.

Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
*/

class Solution {
    public String reverseStr(String s, int k) {
        char[] ch = s.toCharArray();
        
        for(int start = 0; start<ch.length; start += 2*k){
            int i = start, j = Math.min(start+k-1, ch.length-1);
            
            while(i<j){
                char temp = ch[i];
                ch[i++] = ch[j];
                ch[j--] = temp;
                
            }
        }
        
        return new String(ch);
    }
        
}
