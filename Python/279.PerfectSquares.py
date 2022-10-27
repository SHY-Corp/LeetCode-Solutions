class Solution:
    MAXSIZE = 99999
    def numSquares(self, n: int) -> int:
        if n <= 3: return n

        solTable = [0] * (n+1)
        solTable[0] = 0
        solTable[1] = 1
        solTable[2] = 2
        solTable[3] = 3

        for i in range(3,n+1):
            solTable[i] = self.MAXSIZE
            j = 1
            for j in range(1, i-j*j):
                if i-j*j >= 0:
                    solTable[i] = min(solTable[i], solTable[i-j*j])
                else:
                    break
            solTable[i] += 1
        return solTable[n]
