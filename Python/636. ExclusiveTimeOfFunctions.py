#636. Exclusive Time of Functions problem is described here : https://leetcode.com/problems/exclusive-time-of-functions/

class Solution(object):
    def exclusiveTime(self, n, logs):
        """
        :type n: int
        :type logs: List[str]
        :rtype: List[int]
        """
        
        time = [0 for i in range(n)]
        stack = []
        last_timestamp = 0
        for log in logs:
            parts = log.split(":")
            function_id = int(parts[0])
            started = parts[1] == "start"
            timestamp = int(parts[2])
            if not started:
                timestamp += 1
            
            if stack:
                active_id = stack[-1]
                time[active_id] = time[active_id] + (timestamp-last_timestamp)
            if started:
                stack.append(function_id)
            else:
                stack.pop()
            
            last_timestamp = timestamp
        
        return time
