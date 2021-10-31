'''
953. Verifying an Alien Dictionary

Given a sequence of words written in the alien language, and the order of the alphabet, this program
returns true if and only if the given words are sorted lexicographically in this alien language.
'''

class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        dictionary = {}
        index = 0
        # Constructs the lexicographical order of the alien alphabet
        for c in order:
            dictionary[c] = index
            index += 1
        
        for i in range(1, len(words)):
            word1 = words[i-1]
            word2 = words[i]
            size1 = len(word1)
            size2 = len(word2)            
            
            # Checks if two words are the same
            if word1 == word2:
                continue
            # Checks if word 1 is bigger and starts with word 2
            elif word1.startswith(word2) and size1 > size2:
                return False
            # Checks if is not in order
            elif dictionary[word1[0]] > dictionary[word2[0]]:
                return False            
            # Checks if is in order
            elif dictionary[word1[0]] < dictionary[word2[0]]:
                continue
            # If the first n letters are the same checks if the 2 words are ordered
            elif word1[0] == word2[0]:
                min = size1 if size1 < size2 else size2                
                for j in range(1, min):
                    if word1[j] != word2[j] and dictionary[word1[j]] > dictionary[word2[j]]:
                        return False
                    elif word1[j] != word2[j] and dictionary[word1[j]] < dictionary[word2[j]]:
                        break;                
        return True
        