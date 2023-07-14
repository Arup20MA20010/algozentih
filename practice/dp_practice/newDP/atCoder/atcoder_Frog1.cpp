#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;
int h[100100];
int dp[100100];
int rec(int level)
{
    // pruning
    if (level <= 1)
    {
        return 0;
    }
    // base case
    if (level == 2)
    {
        return dp[level] = abs(h[level] - h[level - 1]);
    }
    // cache check
    if (dp[level] != -1)
    {
        return dp[level];
    }
    // transition
    int ans = min(rec(level - 1) + abs(h[level] - h[level - 1]), rec(level - 2) + abs(h[level] - h[level - 2]));
    // save and return
    return dp[level] = ans;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        dp[i] = -1;
    }
    cout << rec(n) << nline;
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