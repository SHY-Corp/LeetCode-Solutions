'''Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]
'''

class Solution(object):
  def groupAnagrams(self, strs):
    List = list(set(map(lambda w: str(sorted(w)), strs))) # We make a second list containing the unique(using set()) letter arrangements, sorted alphabetically
    anagrams = [] # We shall use this to store our grouped anagrams
    i=0
    
    for s in List:  
      anagrams.append([]) # For every unique set of letters we append an empty list to our answer
      for w in strs:
        if str(sorted(w))==s: # If a word in the list contains the exact set of letters
          anagrams[i].append(w) # it is appended to that list which is in the same index position of 'anagrams'
      i+=1

    return anagrams        
