/*Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.*/

class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
      int n = (int)a.size();
      int m = (int)a[0].size();
      vector <vector <int>> dist(n, vector <int> (m, INT_MAX - 1));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (!a[i][j]) {
            dist[i][j] = 0;
          }
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (i != 0) {
            dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
          }
          if (j != 0) {
            dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
          }
        }
      }
      for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
          if (i != n - 1) {
            dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
          }
          if (j != m - 1) {
            dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
          }
        }
      }
      return dist;
    }
};
