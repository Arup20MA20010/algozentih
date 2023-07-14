#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int weights[101];
int v[101];
int dp[101][100100];
int n;
// returns the minumum weight required to create a value of val from level.....n-1
int rec(int level, int val)
{
    if (level == n)
    {
        if (val == 0)
        {
            return 0;
        }
        return 1e18;
    }
    if (val == 0)
    {
        return 0;
    }
    if (val < 0)
    {
        return 1e18;
    }
    if (dp[level][val] != -1)
    {
        return dp[level][val];
    }
    int ans = min(rec(level + 1, val - v[level]) + weights[level], rec(level + 1, val));
    return dp[level][val] = ans;
}
void solve()
{
    int W;
    cin >> n >> W;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i] >> v[i];
        sum += v[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = sum; i > 0; i--)
    {
        if (rec(0, i) <= W)
        {
            ans = i;
            break;
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
    solve();
}