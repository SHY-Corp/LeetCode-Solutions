/*An undirected, connected tree with N nodes labelled 0...N-1 and N-1 edges are given.

The ith edge connects nodes edges[i][0] and edges[i][1] together.

Return a list ans, where ans[i] is the sum of the distances between node i and all other nodes.*/

class Solution {
private:
    vector<int> adj[10005];
    int count[10005];
    int ans[10005];
    int N;
    int dfs1(int node, int par) {
        count[node] = 1;
        int stsum = 0;
        for (int adje : adj[node]) {
            if (adje != par) {
                stsum += dfs1(adje, node) + count[adje];
                count[node] += count[adje];
            }
        }
        return stsum;
    }
    
    void dfs2(int node, int par) {
        for (int adje : adj[node]) {
            if (adje != par) {
                ans[adje] = ans[node] - count[adje] + (N - count[adje]);
                dfs2(adje, node);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        this->N = N;
        for (vector <int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        ans[0] = dfs1(0, -1);
        dfs2(0, -1);
        vector <int> answer(ans, ans + N);
        return answer;
    }
};
