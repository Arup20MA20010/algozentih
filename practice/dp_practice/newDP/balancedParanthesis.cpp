#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
#define MOD 1000000007
string s;
int dp[1001][1001];
int rec(int level, int extra)
{
    if (level == s.length())
    {
        if (extra == 0)
        {
            return 1;
        }
        return 0;
    }
    if (extra < 0)
    {
        return 0;
    }
    if (dp[level][extra] != -1)
    {
        return dp[level][extra];
    }
    if (s[level] == '(')
    {
        return dp[level][extra] = rec(level + 1, extra + 1);
    }
    else if (s[level] == ')')
    {
        return dp[level][extra] = rec(level + 1, extra - 1);
    }
    int ans = rec(level + 1, extra + 1);
    if (extra > 0)
    {
        ans += rec(level + 1, extra - 1);
    }
    return dp[level][extra] = ans % MOD;
}
void solve()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << rec(0, 0) << nline;
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