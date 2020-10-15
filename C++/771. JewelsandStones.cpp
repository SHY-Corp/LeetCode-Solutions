/*
 You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0

 Note:
S and J will consist of letters and have length at most 50.
The characters in J are distinct.
 */

class Solution {
public:
    int numJewelsInStones(string J, string S) {

        // creating an unordered set
        unordered_set<char> hash_set;
        int count=0;

        //iterating through string J and adding it to the hash_set
        for ( int i=0;i<J.length();i++)
            hash_set.insert(J[i]);


        // iterating through the string S
        for ( int j=0 ; j<S.length();j++)
        {
            // finding the corresponding character in hash_set
            if(hash_set.find(S[j])!=hash_set.end())
                count++;
        }

        // returning the final count
        return count;
    }
};