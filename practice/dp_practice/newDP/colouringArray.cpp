#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n, m, k;
int p[101][101];
int dp[101][101][101];
int c[101];
int rec(int level, int b, int state)
{
    // pruning
    if (b > k)
    {
        return 1e18;
    }
    // base case
    if (level == n)
    {
        if (b == k)
        {
            return 0;
        }
        return 1e18;
    }
    // cache check
    if (dp[level][b][state] != -1)
    {
        return dp[level][b][state];
    }
    // transition
    int ans;
    if (c[level] != 0)
    {
        if (c[level] == state)
        {
            ans = rec(level + 1, b, state);
        }
        else
        {
            ans = rec(level + 1, b + 1, c[level]);
        }
        return dp[level][b][state] = ans;
    }
    ans = rec(level + 1, b, state) + p[level][state];
    for (int i = 1; i <= m; i++)
    {
        if (state != i)
        {
            ans = min(rec(level + 1, b + 1, i) + p[level][i], ans);
        }
    }
    return dp[level][b][state] = ans;
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int state = 0; state <= m; state++)
            {
                dp[i][j][state] = -1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++)
    {
        p[i][0] = 0;
        for (int j = 1; j <= m; j++)
        {
            cin >> p[i][j];
        }
    }
    int ans = rec(0, 0, 0);
    cout << (ans < 1e18 ? ans : -1) << nline;
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