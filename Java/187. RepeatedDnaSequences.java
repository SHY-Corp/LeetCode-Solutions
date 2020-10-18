//Leetcode 187. Repeated DNA Sequences in Java
/*
187. Repeated DNA Sequences
Medium
All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T', for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

0 <= s.length <= 105
s[i] is 'A', 'C', 'G', or 'T'.

*/
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        // Declaring the output;
        List<String> repeatedDNA = new ArrayList<>();
        // Map to count the substrings;
        Map<String, Integer> count = new HashMap<>();
        
        // Processing the given DNA string:
        int i = 0;
        while ((i + 10) <= s.length()) {
            String subsequence = s.substring(i, i + 10);
            i++;
            count.put(subsequence, count.getOrDefault(subsequence, 0) + 1);
            if (count.get(subsequence) == 2) {
                repeatedDNA.add(subsequence);
            }
        }
        
        return repeatedDNA;
    }
}
