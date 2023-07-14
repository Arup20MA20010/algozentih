#include <bits/stdc++.h>
using namespace std;
#define nline '\n'
#define int long long
int h[100100];
int dp[100100];
int k;
int n;
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    dp[1] = 0;
    for (int level = 2; level <= n; level++)
    {
        int ans = INT_MAX;
        for (int j = 1; j <= min(level - 1, k); j++)
        {
            ans = min(dp[level - j] + abs(h[level] - h[level - j]), ans);
        }
        dp[level] = ans;
    }
    cout << dp[n] << nline;
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