#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
#define MOD 1000000007
int n, m, k;
int dp[2001][2001];
void solve()
{
    cin >> n >> m >> k;
    for (int level = 0; level < n; level++)
    {
        for (int pos = 0; pos <= min(level, k); pos++)
        {
            if (level == 0 || pos == 0)
            {
                dp[level][pos] = m;
            }
            else
            {
                dp[level][pos] = (dp[level - 1][pos] % MOD + (dp[level - 1][pos - 1] * (m - 1)) % MOD) % MOD;
            }
        }
    }
    cout << dp[n - 1][k] << nline;
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