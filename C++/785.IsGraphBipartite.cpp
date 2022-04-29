/*
   Using the following numbers for colors!
   white = -1, red = 1, blue = 0;
*/
class Solution {
public:
    //this function will now check the nodes adjacent to the current node(i): if its white, it will
    //change to blue and if its already filled, it will check the color of 2 connected nodes
    bool helper_dfs(int i, vector<int>& color, vector<vector<int>>& graph)
    {
        //checking for the nodes connected to ith node
        for(auto u: graph[i])
        {
            if(color[u]==-1)
            {
                //changing the color to blue if its white as we don't want adjacent nodes to have the
                //same color
                color[u] = 1 - color[i];
                //calling the helper function once again to check for the nodes connected to node u
                if(helper_dfs(u, color, graph)==false)
                {
                    return false;
                }
            }
            //if the 2 connected nodes have the same color, they are NOT bipartite
            else if(color[u]==color[i])
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        //initializing a color vector filled with white originally
        vector<int> color(n, -1);

        //traversing over the graph and coloring nodes accordingly
        for(int i=0; i<n; i++)
        {
            if(color[i]==-1)
            {
                //changing the color to red if its white and then calling a helper funtion to check
                //for the adjacent nodes it is connected to
                color[i]=1;
                if(helper_dfs(i, color, graph)==false)
                {
                    //if 2 adjacent nodes have the same color, they are not bipartite as we cannot
                    //partition them into 2 independent sets, thus, return false
                    return false;
                }
            }
        }
        //if the colors are alternating, we can partition them, therefore, return true
        return true;
    }
};

/*
    TC: O(n), since each node of the graph is traversed exactly once
    SC: O(n), for color vector
*/
