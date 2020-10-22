# https://leetcode.com/problems/3sum/

# Given an array nums of n integers, are there elements a, b, c
# in nums such that a + b + c = 0?
# Find all unique triplets in the array which gives the sum of zero.
# Notice that the solution set must not contain duplicate triplets.

from typing import List


def three_sum(nums: List[int]) -> List[List[int]]:
    if not isinstance(nums, list) or any(
        num for num in nums if not isinstance(num, int)
    ):
        raise Exception("You must provide a list containing integers as input")

    sol = []

    # overall solution will have a time complexity if O(n²), so sorting comes
    # for "free"
    nums = sorted(nums)

    # iteration limit considers 3 elements are needed to build a triplet.
    for i in range(0, len(nums) - 2):
        # skip repeated numbers to avoid duplicates in the solution.
        if i > 0 and nums[i] == nums[i - 1]:
            continue

        s, e = i + 1, len(nums) - 1

        while s < e:
            sliding_sum = nums[i] + nums[s] + nums[e]

            if sliding_sum == 0:
                sol.append([nums[i], nums[s], nums[e]])
                s += 1
                e -= 1

                while nums[s] == nums[s - 1] and s < e:
                    s += 1

                while nums[e] == nums[e + 1] and e > s:
                    e -= 1

            if sliding_sum > 0:
                e -= 1
            if sliding_sum < 0:
                s += 1

    return sol
