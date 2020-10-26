# Constraint
# 1 <= n <= 100
# 1 <= logs.length <= 500
# 0 <= function_id < n
# 0 <= timestamp <= 109
# No two start events will happen at the same timestamp.
# No two end events will happen at the same timestamp.
# Each function has an "end" log for each "start" log.

class Solution(object):
    def exclusiveTime(self, n, logs):
        """
        :type n: int
        :type logs: List[str]
        :rtype: List[int]
        """
        res = [0] * n
        stack = []
        prevTime = 0
        for log in logs:
            idx, type, time = log.split(':')
            if type == 'start':
                if stack:
                    res[stack[-1]] += int(time) - prevTime
                stack.append(int(idx))
                prevTime = int(time)
            else:
                res[stack[-1]] += int(time) - prevTime + 1
                stack.pop()
                prevTime = int(time) + 1
        return res