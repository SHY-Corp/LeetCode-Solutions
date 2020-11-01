'''
We are trying to check if a graph is bipartite.

A grpah is said to be bipartite if all the nodes of the graph can be
divided into two distinct sets such that there is no edge between 
the nodes belonging to the same set.

A graph with such a propety can be colored with only two colors.

Thus in this algorithm we will try to color the graph with two
colors and if we can the graph is bipartite else not.

'''

class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        colored = {}
        for i in range(len(graph)):
            if i not in colored and graph[i]:
                colored[i] = 1
                q = collections.deque([i])
                while q:
                    cur = q.popleft()
                    #checking the neighbors of current node
                    for j in graph[cur]:
                        if j not in colored:
                            colored[j] = 1-colored[cur]
                            q.append(j)
                        #neighbor is the same color as the current node
                        elif colored[j] == colored[cur]:
                            return False
        return True
