class Solution {
    //for creating adjacency list between queries with their values
    unordered_map<string, vector<pair<string, double>>> adjList;
    //for marking a node as visited
    unordered_map<string, bool> visited;
    //for storing values of each query via equations
    double queryAns;
public:
    bool helper_dfs(string source, string destination, double crossProduct)
    {
        //if the source and the destination vertices are the same and the source is present in the adjList,
        //update the queryAns with the currentProduct and return true
        if(source == destination && adjList.find(source)!=adjList.end())
        {
            queryAns = crossProduct;
            return true;
        }

        //marking a temp variable as false
        bool temp = false;
        //marking the current source node as visited
        visited[source] = true;

        //iterating over the nodes connected to the current cource node
        for(int i=0; i<adjList[source].size(); i++)
        {
            //if the node is not visited, call the helper function once again to check if there is a path
            if(!visited[adjList[source][i].first])
            {
                temp = helper_dfs(adjList[source][i].first, destination, crossProduct*adjList[source][i].second);
                //if there is a path, break out of the loop
                if(temp)
                {
                    break;
                }
            }
        }
        //reset the source node as not visited
        visited[source] = false;
        //return if there is a path or not
        return temp;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int n = equations.size();
        int m = queries.size();
        vector<double> v(m);

        //create an adjacency list for the given nodes(equations)
        for(int i=0; i<n; i++)
        {
            //if path from a->b has a weight of 2, then path from b->a will have a weight of 1/2
            adjList[equations[i][0]].push_back({equations[i][1], values[i]});
            adjList[equations[i][1]].push_back({equations[i][0], 1/values[i]});

            //marking the nodes as false indicating they haven't been visited yet
            visited[equations[i][0]] = false;
            visited[equations[i][1]] = false;
        }

        //traversing over each vertex(of given query) and upadting the result vector v
        for(int i=0; i<m; i++)
        {
            queryAns = 1;
            //helper function for checking path b/w subsequent nodes of the query and updating their values
            bool pathFound = helper_dfs(queries[i][0], queries[i][1], 1);
            if(pathFound)
                v[i] = queryAns;
            else
                v[i] = -1;
        }
        return v;
    }
};

/*
      TC = O(VQ), where V = Vertices on your graph and Q = No. of queries.
      SC = O(n), where n = size of result array
*/
