'''

Problem asked us to find all possible paths from node 0 to node n - 1, and return them in any order in a given Directed Acyclic Graph (https://en.wikipedia.org/wiki/Directed_acyclic_graph)
Provided parameters : graph[i] a list of all nodes we can visit from node i (i.e., there is a directed edge from node i to node graph[i][j] )
Link : https://leetcode.com/problems/all-paths-from-source-to-target/

Note : 0 is always the root Node and N-1 is always the Target Node

Approach :
recursive DFS approach 



'''
class Solution:
    def allPathsSourceTarget(self, g: List[List[int]]) -> List[List[int]]:
        ans = []
        
        #DFS function with parameters node to be traversed and the path formed before that state
        def dfs(node, path):
             # If we reached (n-1)th node then add it to our answer 
            if node == len(g) -1:
                ans.append(path)
                return
            
            # Traverse all paths from node to all its children g[node] one by one by calling dfs on them recursively and add num to our path
            for num in g[node]:
                dfs(num, path + [num])
                
        #call the dfs function on root node 
        dfs(0, [0])
        
        return ans
