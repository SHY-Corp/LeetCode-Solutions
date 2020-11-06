/*
1408. String Matching in an Array
Problem link : https://leetcode.com/problems/string-matching-in-an-array/

Given an array of string words. Return all strings in words which is substring of another word in any order. 

String words[i] is substring of words[j], if can be obtained removing some characters to left and/or right side of words[j].

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.

*/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> matched;
		int i,j;
		//Checking every word in the string vector with all other words other than itself to find if it is substring of another word
        for(i=0;i<words.size();i++)	
		{
            for(j=0;j<words.size();j++)	
			{
               if(i!=j)
			   {
				   //Using find function to check for occurrence of a word(string) in another word(string)
                   size_t found=words[j].find(words[i]);
				   //If substring found, then push it to a string vector which will be returned by the fuction
                   if(found!=string::npos)
				   {
                       matched.push_back(words[i]);	
                       break;
                   }
               }
            }
        }
        return matched;
        
    }
};