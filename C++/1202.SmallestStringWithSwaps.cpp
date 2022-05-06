/*
   Treating letters as nodes of an undirected graph in this question
*/
class Solution {
public:
    //graph
    vector<vector<int>> g;
    //vector for marking visited nodes
    vector<bool> visited;

    //dfs function call to mark a node visited if it's not and push that node and its index into
    //respective their vectors
    void dfs(int i, vector<int>& index, vector<char>& letters, string &s)
    {
        visited[i] = true;
        index.push_back(i);
        letters.push_back(s[i]);

        //checking for a node's neighbour and making a dfs call again if that node isn't visited
        for(int u: g[i])
        {
            if(!visited[u])
            {
                dfs(u, index, letters, s);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        g.resize(n);
        //marking all the spaces as false indicating that this node has not been visited yet
        visited.resize(n, false);

        //connecting nodes given in a pair(undirected)
        for(auto x: pairs)
        {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }

        for(int i=0; i<n; i++)
        {
            //mainitaining a vector for indices of the given string
            vector<int> index;
            //for storing characters of the string
            vector<char> letters;

            //processing the ith node through a dfs call if the node is not visited
            if(!visited[i])
            {
                dfs(i, index, letters, s);
            }

            //sorting both the vectors
            sort(begin(index), end(index));
            sort(begin(letters), end(letters));

            //marking the indices of the sorted index vector with the sorted letters vector
            for(int i=0; i<index.size(); i++)
            {
                s[index[i]] = letters[i];
            }
        }
        return s;
    }
};

/*
   Time complexity: O(E+VlogV)
   Space complexity: O(E+V)
*/
