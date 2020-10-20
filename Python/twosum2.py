class Solve:
    
    def TwoSum(self, nums: List[int], target: int) -> List[int]:
        hashes = dict()
        for i, num in enumerate(nums):
            index = target - num
            if index not in hashes:
                hashes[num] = i
            else:
                return [hashes[index], i]
