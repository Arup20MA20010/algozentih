#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int row[3001001];
int dp[3001001];
int ans[3001001];
void precompute()
{
    int N = 2023;
    // assigned the row to each of the number
    for (int r = 1; r <= N; r++)
    {
        for (int i = r * (r - 1) / 2 + 1; i <= r * (r + 1) / 2; i++)
        {
            row[i] = r;
        }
    }
    // creating the dp array
    for (int r = 1; r <= N; r++)
    {
        int first = r * (r - 1) / 2 + 1;
        dp[first] = first * first;
        int inc = r;
        for (int j = first; j <= (N * (N + 1) / 2) - r + 1; j += inc)
        {
            if (j != first)
            {
                dp[j] = j * j + dp[j - inc];
            }
            inc++;
        }
    }
}
int n;
void solve()
{
    cin >> n;
    int r = row[n];
    int t = (r * (r + 1) / 2) - n + 1;
    int f = (r - t + 1) * (r - t + 2) / 2;
    int inc = r - t;
    int ans = dp[f];
    for (int j = f; j <= n; j += inc)
    {
        if (j != f)
        {
            ans += dp[j];
        }
        inc++;
    }
    cout << ans << nline;
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
    precompute();
    while (t--)
    {
        solve();
    }
    return 0;
}