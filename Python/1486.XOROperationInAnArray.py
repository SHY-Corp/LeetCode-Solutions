class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        nums = []
        for i in range(n):
            suma = start+2*i
            nums.append(suma)
        suma = 0
        for k in range(n):
            suma = suma^nums[k]
        return suma
        
