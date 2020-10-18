// Java Solution whose Runtime beats 95/71% of all submissions for problem 797 | All Paths from Source to Target
/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1, and return them in any order.
The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).
 
Example 1:
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Example 2:
Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
Example 3:
Input: graph = [[1],[]]
Output: [[0,1]]
Example 4:
Input: graph = [[1,2,3],[2],[3],[]]
Output: [[0,1,2,3],[0,2,3],[0,3]]
Example 5:
Input: graph = [[1,3],[2],[3],[]]
Output: [[0,1,2,3],[0,3]]
 
Constraints:
n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i (i.e., there will be no self-loops).
The input graph is guaranteed to be a DAG.
*/

//DFS Approach

class Solution {
    public void getPath(int[][] graph, int i, int dest, List<Integer> path, List<List<Integer>> res){
        if(i==dest){
            res.add(new ArrayList<Integer>(path));
            return;
        }
        for(int adj:graph[i]){
            path.add(adj);
            getPath(graph, adj, dest, path, res);
            path.remove(path.size()-1);
        }
    }
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> res=new ArrayList<>();
        if(graph.length==0 || graph==null)
            return res;
        List<Integer> path=new ArrayList<>();
        path.add(0);
        getPath(graph, 0, graph.length-1, path, res);
        return res;
    }
}