  class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        # This is solved using dynamic programming approach
        # Initially we create a dp matrix for elements in target
        dp = [[[]]] + [[] for _ in range(target)]
        for candidate in candidates:
        # Next we iterate for all candidate in canditates and then later iterate from candidate to target+1
            for i in range(candidate,target+1):
                dp[i] += [sublist + [candidate] for sublist in dp[i-candidate]]
                # Here we compute dp using the above method
                # This is done by once again iterating over every sublist in the initial list we iterated.
        return dp[target]
        # Returns answer
