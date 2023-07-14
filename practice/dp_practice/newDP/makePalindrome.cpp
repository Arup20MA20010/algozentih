#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[1001][1001];
string s;
int rec(int l, int r)
{
    if (l >= r)
    {
        return 0;
    }
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    int ans = 0;
    if (s[l] == s[r])
    {
        ans = rec(l + 1, r - 1);
    }
    else
    {
        ans = min(rec(l, r - 1) + 1, rec(l + 1, r) + 1);
    }
    // save and return
    return dp[l][r] = ans;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> s;
    n = s.length();
    cout << rec(0, n - 1) << nline;
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