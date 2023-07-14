#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;
int W;
int w[110];
int v[110];
int dp[110][100100];
int rec(int level, int remSum)
{
    if (remSum < 0)
    {
        return -1e18;
    }
    if (level == n)
    {
        return 0;
    }
    if (dp[level][remSum] != -1)
    {
        return dp[level][remSum];
    }
    dp[level][remSum] = max(rec(level + 1, remSum), rec(level + 1, remSum - w[level]) + v[level]);
    return dp[level][remSum];
}
void solve()
{
    cin >> n >> W;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    cout << rec(0, W) << nline;
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
    solve();
    return 0;
}