#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;
vector<string> s;
vector<string> rev;
int dp[100100][2];
int cost[100100];
int rec(int level, int state)
{
    if (level == 1)
    {
        return min(rec(2, 0), rec(2, 1) + cost[1]);
    }
    if (level == n + 1)
    {
        return 0;
    }
    if (dp[level][state] != -1)
    {
        return dp[level][state];
    }
    int ans = 1e18;
    if (state == 0)
    {
        if (s[level - 1] <= rev[level])
        {
            ans = min(ans, rec(level + 1, 1) + cost[level]);
        }
        if (s[level - 1] <= s[level])
        {
            ans = min(ans, rec(level + 1, 0));
        }
    }
    else
    {
        if (rev[level - 1] <= rev[level])
        {
            ans = min(ans, rec(level + 1, 1) + cost[level]);
        }
        if (rev[level - 1] <= s[level])
        {
            ans = min(ans, rec(level + 1, 0));
        }
    }
    return dp[level][state] = ans;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    s.resize(n + 1);
    rev.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        rev[i] = s[i];
        reverse(rev[i].begin(), rev[i].end());
    }
    int ans = rec(1, 0);
    cout << (ans >= 1e18 ? -1 : ans) << nline;
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