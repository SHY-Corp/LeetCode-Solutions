from typing import List

class Solution:
    def countBits(self, num: int) -> List[int]:
        result = [bin(i).count('1') for i in range(num + 1)]
        return result
