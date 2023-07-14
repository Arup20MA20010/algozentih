#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
#define MOD 1000000007
string s;
int n;
int dp[100100];
int last[27];
int sum[100100];
void solve()
{
    cin >> s;
    n = (int)s.length();
    dp[0] = 1; // empty string
    sum[0] = 1;
    memset(last, 0, sizeof(last));
    for (int i = 1; i <= n; i++)
    {
        dp[i] = sum[i - 1] % MOD;
        if (last[s[i - 1] - 'A'])
        {
            dp[i] = (dp[i] - sum[last[s[i - 1] - 'A'] - 1] + MOD) % MOD;
        }
        sum[i] = (sum[i - 1] % MOD + dp[i] % MOD) % MOD;
        last[s[i - 1] - 'A'] = i;
    }
    cout << sum[n] % MOD << nline;
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