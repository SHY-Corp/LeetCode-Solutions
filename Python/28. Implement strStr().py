'''
28. Implement strStr()

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
If the needle is empty return 0.
'''

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        sizeOfNeedle = len(needle)
        sizeOfHaystack = len(haystack)
        if sizeOfNeedle == 0 or haystack == needle:
            return 0
        if(sizeOfHaystack < sizeOfNeedle):
            return -1
        
        for i in range(0, sizeOfHaystack):
            bound = i + sizeOfNeedle
            if bound > sizeOfHaystack:
                return -1
            
            substring = haystack[i:bound]
            if substring == needle:
                return i
            
        return -1