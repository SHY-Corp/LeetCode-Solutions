/*
 *
Problem:
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

 Example 1:
 Input: ransomNote = "a", magazine = "b"
 Output: false


 Example 2:
 Input: ransomNote = "aa", magazine = "aab"
Output: true


 Example 3:
 Input: ransomNote = "aa", magazine = "ab"
Output: false

 Approach/ Solution:
  Idea is to check that every character in the ransomNote exists in the magazine
  How to do that you can make 2 arrays freqency arrays of size 26 (number of characters in the alphabet), for both ransomNote and magazine.
  then compare each occuracnce of each element in ransomNote frequency array if it's less than or equal that of the magazine we are good, else we cannot construct
 * */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int FreqRansomNote[26]={0},FreqMagzine[26]={0};
        for(int i=0;i<ransomNote.size();i++)
            FreqRansomNote[ransomNote[i]-'a']++;
        for(int i=0;i<magazine.size();i++)
            FreqMagzine[magazine[i]-'a']++;
        for(int i=0;i<26;i++)
        {
            if(FreqRansomNote[i]>FreqMagzine[i])
                return false;
        }
        return true;

    }
};


