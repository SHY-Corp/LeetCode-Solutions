/*
The idea is to use a 2D array to keep track of the total possible ways to enter specific block.
Since we can only go "DOWN" and "RIGHT", therefore each block could be entered from both "ABOVE" and "LEFT", therefore adding up their total ways would give the total ways for current block.
In order to save the hassles in the future, it's easier that we initialize the array
which is why dp[1][0]=1

Following is the code

*/
  public static int uniquePaths(int m, int n) {
    int[][] dp = new int[n + 1][m + 1];
    dp[1][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[n][m];
  }
