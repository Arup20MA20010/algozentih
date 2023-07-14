#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[100100][4];
int n;
int a[100100], b[100100], c[100100];
int rec(int level, int config)
{ // maximum hapiness given config at level-1 is config from level to n
    // base case and pruning
    if (level == n + 1)
    {
        return 0;
    }
    // cache check
    if (dp[level][config] != -1)
    {
        return dp[level][config];
    }
    // transitions
    int ans = 0;
    if (config == 0)
    {
        ans = max(rec(level + 1, 1) + a[level], max(rec(level + 1, 2) + b[level], rec(level + 1, 3) + c[level]));
        }
    else if (config == 1)
    {
        ans = max(rec(level + 1, 2) + b[level], rec(level + 1, 3) + c[level]);
    }
    else if (config == 2)
    {
        ans = max(rec(level + 1, 1) + a[level], rec(level + 1, 3) + c[level]);
    }
    else
    {
        ans = max(rec(level + 1, 1) + a[level], rec(level + 1, 2) + b[level]);
    }
    // save and return
    return dp[level][config] = ans;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        for (int config = 0; config < 4; config++)
        {
            dp[i][config] = -1;
        }
    }
    cout << rec(1, 0) << nline;
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