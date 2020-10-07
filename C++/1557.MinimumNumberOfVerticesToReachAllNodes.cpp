/* Given a graph, we need to find the smallest set of vertices from which all nodes in the graph are reachable .
   So, we will mark all the nodes that are reachable from any other node as true and in the last, we will check which nodes have their in-degree as 0.
   The nodes with 0 in-degree would be our answer.
*/


class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        bool visited[n];
        for(int i = 0; i < n; i++){
            visited[i] = false;
        }
        /* All the nodes that are reachable from any other node will be marked as true */
        for(vector<int> i : edges){
            visited[i[1]] = true;
        }
        /* Nodes with in-degree 0 would be added to the ans vector */
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};