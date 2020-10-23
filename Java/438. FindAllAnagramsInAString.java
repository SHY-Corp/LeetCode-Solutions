/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

//Sliding Window Solution - Runtime beats 87.16% of all submissions

class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        //Constant length sliding window 
        
        List<Integer> list = new ArrayList<>();
        int pLen = p.length();
        int sLen = s.length();
        
        //corner cases
        if(pLen == 0 || sLen == 0)
            return list;
        if(sLen < pLen)
            return list;
            
        int[] pattern = new int[26];
        int[] window = new int[26];
        
        //framing k-length window; k here is pLen
        
        for(int i = 0 ; i<pLen ; ++i){
            ++pattern[p.charAt(i) - 'a'];
            ++window[s.charAt(i) - 'a'];
        }
        
        if(Arrays.equals(pattern, window))
            list.add(0);
        
        //iterating through the string
        for(int i = pLen ; i<sLen ; ++i){
            
            //removing (i-k)th element from window
            if(window[s.charAt(i-pLen) - 'a'] != 0)
                --window[s.charAt(i-pLen) - 'a'];
            
            //add the ith element to window
            ++window[s.charAt(i) - 'a'];
            
            //check if frquency is same i.e equal to that of anagram
            if(Arrays.equals(pattern, window))
                list.add(i-pLen+1);
        }
        return list;
    }
}
