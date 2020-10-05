class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        even=0
        odd=len(A)-1
        
        while even<odd:
            if A[even]%2 == 0:
                even+=1
            else:
                if A[odd]%2 == 0:
                    tmp=A[odd]
                    A[odd]=A[even]
                    A[even]=tmp
                odd-=1
        return A
        
