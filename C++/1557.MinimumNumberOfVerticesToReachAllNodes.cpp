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