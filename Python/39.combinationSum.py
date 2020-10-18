  class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        dp = [[[]]] + [[] for _ in range(target)]
        for candidate in candidates:
            for i in range(candidate,target+1):
                dp[i] += [sublist + [candidate] for sublist in dp[i-candidate]]
        return dp[target]
