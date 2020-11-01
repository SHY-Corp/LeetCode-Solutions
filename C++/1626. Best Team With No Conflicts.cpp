/** This is very interesting DP problem which requires some observation
 *  So the problem says that we want to maximize the team score such that there is no conflict.
 *  Conflict only occurs if we select a player which has strictly higher score but strictly less age than another player.
 *  If you try to hand run some random test cases, then you may observe the following things:
 *      1. We need to sort the given data first by age then by score.
 *      2. Now after sorting we only need to find the maximum sum increasing subsequence (MSIS) from the given data, which is classical DP problem.
 *  In the code I have first made vector of pairs to sort the data. Then I have applied DP to get MSIS.
 *  For MSIS tutorial : https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/
 */

int bestTeamScore(vector<int> &scores, vector<int> &ages) {
    vector <pair<int, int>> data;
    vector<int> dp(ages.size(), 0);
    for (int i = 0; i < ages.size(); ++i) {
        data.push_back(make_pair(ages[i], scores[i])); //making pairs
    }
    sort(data.begin(), data.end()); // sorting the data
    for (int i = 0; i < data.size(); ++i) { //Code for MSIS
        dp[i] = max(dp[i], data[i].second);
        for (int j = i - 1; j >= 0; --j) {
            if (data[i].second >= data[j].second) {
                dp[i] = max(dp[i], dp[j] + data[i].second);
            }
        }
    }

    int ans = 0;
    for (int i :dp) ans = max(ans, i); // Maximum sum to be returned
    return ans;
}

