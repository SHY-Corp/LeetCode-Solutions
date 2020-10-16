class Solution {
public:
   bool isBipartite(vector<vector<int>>& adj) 
   {
        int n=adj.size();
 
       vector<int>color(n,-1);
       
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                queue<int> q;
                q.push(i);
                color[i]=1;
                
                while(!q.empty())
                {
                    int v=q.front();
                    q.pop();
                    
                    for(auto u: adj[v])
                    {
                        if(color[u]==-1)   
                        {
                            color[u]= 1- color[v];
                            q.push(u);
                        }
                        else if(color[u]==color[v])
                        {
                             return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};