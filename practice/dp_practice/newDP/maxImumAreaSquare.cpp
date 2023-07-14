#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            dp[0][j] = arr[0][j];
            dp[i][0] = arr[i][0];
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                int l = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                l = sqrt(l) + 1;
                dp[i][j] = l * l;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, dp[i][j]);
        }
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