#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
#define MOD 1000000007
int n, m, k;
int dp[201][201][401];
int arr[201][201];
int addMOD(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}
void solve()
{
    cin >> n >> m >> k;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (i == 0 && j == 0)
            {
                dp[i][j][0] = 1 - arr[i][j];
            }
            if (i > 0)
            {
                dp[i][j][0] = addMOD(dp[i][j][0], dp[i - 1][j][0] * (1 - arr[i - 1][j]));
            }
            if (j > 0)
            {
                dp[i][j][0] = addMOD(dp[i][j][0], dp[i][j - 1][0] * (1 - arr[i][j - 1]));
            }
            dp[i][j][0] = (dp[i][j][0] * (1 - arr[i][j])) % MOD;
        }
    }
    dp[0][0][1] = arr[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int t = 1; t <= k; t++)
            {
                if (i > 0)
                {
                    dp[i][j][t] = addMOD(dp[i][j][t], dp[i - 1][j][t - arr[i][j]]);
                }
                if (j > 0)
                {
                    dp[i][j][t] = addMOD(dp[i][j][t], dp[i][j - 1][t - arr[i][j]]);
                }
            }
        }
    }

    int ans = 0;
    for (int t = 0; t <= k; t++)
    {
        ans = addMOD(ans, dp[n - 1][m - 1][t]);
    }
    cout << ans << nline;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}