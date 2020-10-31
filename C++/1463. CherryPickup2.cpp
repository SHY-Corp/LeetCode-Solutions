class Solution {
public:
    // Using Dynamic Programing 
    int cherryPickup(vector<vector<int>>& grid) {
        // m = number of rows
        int m = grid.size();

        // n = number of columns
        int n = grid[0].size();
        
        int f[m][n][n];

        int res = 0;
        
        // initializing array with -1
        memset(f, -1, sizeof(f));

        f[0][0][n - 1] = grid[0][0] + grid[0][n-1];
        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++) {
                    // f[i][j][k] is the maximum number of cherries collection in which robot 1 is at (i, j), and robot 2 is at (i, k).
                    int value = (j == k) ? grid[i][j] : grid[i][j] + grid[i][k];
                    for (int col1 = j-1; col1 <= j+1; col1++)
                        for (int col2 = k-1; col2 <= k+1; col2++) {
							if (col1 >= 0 && col1 < n && col2 >= 0 && col2 < n && f[i-1][col1][col2] >= 0) {
                                // F[i][j][k] = max(F[i-1][col1][col2] + grid[i-1][col1] + grid[i-1][col2]) (col1 can reach to j on the next step, col2 can reach to k on the next step)
                                f[i][j][k] = max(f[i][j][k], f[i - 1][col1][col2] + value);
                                if (i == m - 1) res = max(res, f[i][j][k]);
                            }
                        }
                }
        return res;
    }
};
