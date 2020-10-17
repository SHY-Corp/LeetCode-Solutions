class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        a = s.split()
        if (len(a)>=1):
            return len(a[-1])
        else:
            return 0
