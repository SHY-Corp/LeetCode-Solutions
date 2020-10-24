class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        # Since all the three parts are equal, if we sum all element of arrary it should be a multiplication of 3
        # so the sum of each part must be equal to sum of all element divided by 3
        quotient, remainder = divmod(sum(A), 3)

        if remainder != 0:
          return False
        
        subarray = 0
        partitions = 0
        for num in A:
          subarray += num
          if subarray == quotient:
            partitions += 1
            subarray = 0
        
        # Check if it consist at least 3 partitions
        return partitions >= 3