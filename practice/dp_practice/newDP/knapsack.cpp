#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nline '/n'
int n, W;
int dp[1010][1010];
int p[1010];
int w[1010];
int maxProfit(int level, int weights)
{
    if (weights > W)
        return -1e9;
    if (level == n)
        return 0;
    if (dp[level][weights] != -1)
        return dp[level][weights];
    return dp[level][weights] = max(p[level] + maxProfit(level + 1, weights + w[level]), maxProfit(level + 1, weights));
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << maxProfit(0, 0) << nline;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}