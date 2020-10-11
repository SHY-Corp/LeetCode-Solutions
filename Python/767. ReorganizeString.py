#767. Reorganize String problem is described here : https://leetcode.com/problems/reorganize-string/

class Solution:
    def reorganizeString(self, S: str) -> str:
        reorg = [None] * len(S)
        letters = [[S.count(c), c] for c in set(S)]
        letters.sort(reverse=True)

        i = 0
        for count, c in letters:
            while count:
                reorg[i] = c
                i += 2
                if i >= len(S):
                    i = 1
                count -= 1
        for i in range(len(reorg) - 1):
            if reorg[i] == reorg[i + 1]:
                return ""
        return "".join(reorg)
