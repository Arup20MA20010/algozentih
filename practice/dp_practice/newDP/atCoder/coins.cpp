#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;
long double p[3000];
long double dp[3001][3001];
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    dp[0][1] = p[0];
    dp[0][0] = 1.0 - p[0];
    for (int level = 1; level < n; level++)
    {
        for (int i = 0; i <= level + 1; i++)
        {
            dp[level][i] = dp[level - 1][i] * (1 - p[level]);
            if (i >= 1)
            {
                dp[level][i] += dp[level - 1][i - 1] * p[level];
            }
        }
    }
    long double ans = 0.0;
    for (int i = n / 2 + 1; i <= n; i++)
    {
        ans += dp[n - 1][i];
    }
    cout << setprecision(10) << ans << nline;
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