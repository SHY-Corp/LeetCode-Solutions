
/*
* Given an undirected graph, return true if and only if it is bipartite.
*
* Input: graph = [[1,3],[0,2],[1,3],[0,2]]
* Output: true
* Explanation: We can divide the vertices into two groups: {0, 2} and {1, 3}.
*
* Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
* Output: false
* Explanation: We cannot find a way to divide the set of nodes into two independent subsets.

*/


class Solution
{
public:
    bool isBipartite(vector<vector<int>>& g)
    {
        int n = g.size();

        vector<int>color(n,-1);

        for(int i=0;i<n;i++)
       {
            if(color[i] == -1)             // if the color is not assigned choose it
                {
                    if(!ani(g,n,i,color) )       // traverse all the nodes dfs way
                    return false;
                }
        }

    return true;
  }


  public:
     bool ani(vector<vector<int>>&g ,int n,int node,vector<int>&color)
     {
         queue<int>Q;

         Q.push(node); // insert the element in the queue

         color[node] = 1;  // parent color

         while(!Q.empty())
         {
             int curr = Q.front();      // pop the front element from the queue
             Q.pop();

             for(auto ele:g[curr])          // traversing the adj elements
             {
                 if(color[ele] == color[curr])   // if  color is same as the parent color then it does not the conditions of  bipartite graph.
                     return false;
                 else if(color[ele] == -1)
                 {
                     color[ele] = 1- color[curr];      // else assign opposite to that of parent node
                     Q.push(ele);                     // push them into the queue
                 }
             }

         }

         return true;
     }

};
