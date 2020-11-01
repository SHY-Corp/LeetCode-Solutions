/*
859. Buddy Strings

Problem
Given two strings A and B of lowercase letters, return true if you can swap two letters in A so the result is equal to B, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at A[i] and A[j]. For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

Example 1:

Input: A = "ab", B = "ba"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal to B.
Example 2:

Input: A = "ab", B = "ab"
Output: false
Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b', which results in "ba" != B.
Example 3:

Input: A = "aa", B = "aa"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'a' to get "aa", which is equal to B.
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false




Approach:
1- Count subscripts of characters in the character strings A and B that do not match.

2- When the number of unmatched subscripts is not equal to 0 or 2, B cannot be obtained from A.

3- When the number of unmatched subscripts is equal to 0, the characters in A and B are exactly the same, and there are also repeated characters in A.

4 -When the number of unmatched subscripts is equal to 2, it is judged whether they match after exchanging two pairs of characters.





*/





class Solution {
public:
  bool buddyStrings(const string & a, const string & b) {
    if (a.size() != b.size()) return false;
    vector < int > index_of_mismatch;
    for (int i = 0; i < a.size(); i++)
      if (a[i] != b[i]) {
        index_of_mismatch.push_back(i);
        if (2 < index_of_mismatch.size()) return false;
      }
    if (index_of_mismatch.size() == 0) {
      return set < char > (a.begin(), a.end()).size() < a.size();
    } else if (index_of_mismatch.size() == 2) {
      return a[index_of_mismatch[0]] == b[index_of_mismatch[1]] &&
        a[index_of_mismatch[1]] == b[index_of_mismatch[0]];
    }
    return false;
  }
};