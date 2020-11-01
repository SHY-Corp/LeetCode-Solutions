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
        char[] ch = s.toCharArray(); // converting string to character array as strings are immutable
        
        for(int start = 0; start<ch.length; start += 2*k){ // start += 2*k -> since we are only allowed to reverse every k characters in 2k characters
            int i = start, j = Math.min(start+k-1, ch.length-1); /* defining our start and end point. j -> if after reversing k characters in 2k characters, if the 
                                                                  length of string is less than k, j -> ch.length-1 otherwise j -> start+k-1; */
            while(i<j){
                char temp = ch[i];
                ch[i++] = ch[j]; // simple reversing 
                ch[j--] = temp;
                
            }
        }
        
        return new String(ch); // converting back to string
    }
        
}
