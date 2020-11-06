/*
* N couples sit in 2N seats arranged in a row and want to hold hands.
* We want to know the minimum number of swaps so that every couple is sitting side by side
* 
*  Example 1:
* Input: row = [0, 2, 1, 3]
* Output: 1
* Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
* 
* Example 2:
* Input: row = [3, 2, 0, 1]
* Output: 0
* Explanation: All couples are already seated side by side.

*/

class Solution {
public:

  void dfs(vector<vector<int>> &adj, int node, vector<bool> &visited)
  {
        visited[node] = true ;                   // markng all the nodes as true in visited vector

        for(auto x : adj[node])              // traversing the adjacent nodes of the given node 
        {
            if(!visited[x])              
                dfs(adj,x,visited);
        }
   
   return ;
  }

    int minSwapsCouples(vector<int>& row) 
    {
        // minimum swaps to sort
        // cycle detection
        int n  = row.size() ;
        vector <bool>visited(n/2,0);        // intalising the visited vector of size n/2
        int ans = 0 ;

        unordered_map<int,int> mp;
        vector<vector<int>> adj(n/2);

        for(int i=0; i<n; i++){
            mp[row[i]] = i ;                  // marking the freq of the element in the map
        }

        for(int i=0; i<n-1; i+=2){
            int temp = mp[i];
            int temp2= mp[i+1];
            if(temp/2 == temp2/2) continue ;
            else {
                int node1 = temp/2;
                int node2 = temp2/2 ;
                adj[node1].push_back(node2);     // traversing the nodes and make a edges between them
                adj[node2].push_back(node1);
            }
        }
        for(int i=0; i<n/2 ; i++){
            if(!visited[i])
            {                   // if the node is not visited then call the node
                ans++;
                dfs(adj, i, visited);
            }
        }

        return n/2-ans;   // after counting the numner of connected components we subtract it from half the number of nodes

    }
};
