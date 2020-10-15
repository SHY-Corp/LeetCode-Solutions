// Problem - 547. Friend Circles

/*
    We will do this problem using DFS. So we will have a vector containing the visited friends
    with the variable name visited, it will initially contain all 0s and have a size of M.

    When we iterate through M, we check if we have visited that friend yet. If we have not, then we perform
    DFS on that friend and mark all of its friend as visited as well. If we have, then we continue iterating.

    Finally we will be able to find out how many friend circles are available in the matrix M.
*/

class Solution {
   public:
    void dfs(vector<vector<int>> &M, vector<int> &visited, int currentFriend) {
        for (int i = 0; i < M.size(); i++) {
            if (M[i][currentFriend] == 1 && visited[i] == 0) {
                visited[i] = 1;
                dfs(M, visited, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &M) {
        vector<int> visited(M.size(), 0);
        int totalGroup = 0;
        for (int i = 0; i < M.size(); i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                totalGroup++;
                dfs(M, visited, i);
            }
        }
        return totalGroup;
    }
};