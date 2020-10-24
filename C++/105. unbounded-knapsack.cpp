#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int N, K, arr[2100], memo[2100][2100];

int dp(int idx, int sum)
{
    if (memo[idx][sum] != -1)
        return memo[idx][sum];
    if (idx == N || sum == K)
        return 0;
    if (sum > K)
        return -INF;

    return memo[idx][sum] = max(dp(idx + 1, sum), arr[idx] + dp(idx, sum + arr[idx]));
}

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int T;

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &K);
        for (int a = 0; a < N; a++) {
            scanf("%d", &arr[a]);
        }

        memset(memo, -1, sizeof(memo));
        printf("%d\n", dp(0, 0));
    }
}
