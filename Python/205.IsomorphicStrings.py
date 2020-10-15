# Having 2 strings s1, s2 isIsomorphic checks if s1 can be changed into s2
# by replacing letters of s1
class Solution:
    def isIsomorphic(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False

        mapping = {}

        for letter1, letter2 in zip(s1, s2):
            if not letter1 in mapping:
                mapping[letter1] = letter2
                continue

            if mapping[letter1] != letter2:
                return False

        return len(mapping) == len(set(mapping.values()))
