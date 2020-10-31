class Solution {
  public int mincostTickets(int[] days, int[] costs) {
    // creating a dp table for all days in a year
    int[] dp = new int[365 + 1];
    dp[0] = 0;  // base case
    int p = 0;

    for (int i = 1; i < dp.length; ++i) {
      dp[i] = dp[i - 1];  // default scenario

      if (p < days.length && i == days[p]) {
        dp[i] = dp[i] + costs[0];   // dp case when buying ticket for a single day pass

        if (i - 7 > 0)    // dp case when buying ticket for 7 days
          dp[i] = Integer.min(dp[i - 7] + costs[1], dp[i]);
        else
          dp[i] = Integer.min(dp[0] + costs[1], dp[i]);

        if (i - 30 > 0)   // dp case when buying ticket for a month (30 days)
          dp[i] = Integer.min(dp[i - 30] + costs[2], dp[i]);
        else
          dp[i] = Integer.min(dp[0] + costs[2], dp[i]);

        ++p;
      }
    }
    // System.out.println(Arrays.toString(dp));
    return dp[days[days.length - 1]];
  }
}
