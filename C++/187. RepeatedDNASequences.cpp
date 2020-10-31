/*
187. Repeated DNA Sequences



Problem


All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T', for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.


Example 1:


Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]


Example 2:
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]





Approach
This is a very basic and easy problem if space is not a problem.

What makes it a hard one is because if you have a HashSet of String to keep all appearing DNA Sequences, it needs too much storing memory.

The trick to handle this is to use Set of Integer instead of String. Because each character has only 4 possible values: A, C, G, T. So that it could be converted to 2 bit integer: 0, 1, 2, 3. In order to represent 10-letter-long sequence, we only need 10 * 2 = 20 bit. Since Integer is 32 bit long, so a Integer is already good enough to represent a 10 letter long DNA sequence.

Having this “ACGT” to “0123” converting system, the problem could be solved easily and efficiently.


So the algorithm goes as follows:
1. Search from the start of the string, get every substr with length 10.
2. Construct and look up a hashmap, add 1 to the value.
3. After the whole search, check every entry in the hashmap, if the value is greater than 1, output.
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        
        int key = 0;
        unsigned hashTable[1<<20] = {0}; // 0x00000-0xfffff
        for(int i=0; i<s.length();i++){
            
            key = (key << 2 | (s[i]+1)%5) & 0xfffff;
            if(i < 9) continue;
            
            if(hashTable[key] == 1){
                ans.push_back(s.substr(i-9,10));
            }
            
            hashTable[key]++;
        }
        
        return ans;
    }
    
};