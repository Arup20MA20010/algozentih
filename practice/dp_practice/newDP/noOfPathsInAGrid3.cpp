#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
#define MOD 1000000007
int n, m, k;
int arr[201][201];
int dp[201][201][201];
int addMOD(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}
int rec(int i, int j, int moves)
{
    if (moves > k)
    {
        return 0;
    }
    if (i == n - 1 && j == m - 1)
    {
        return 1 - arr[i][j];
    }
    if (i == n || j == m)
    {
        return 0;
    }
    if (arr[i][j])
    {
        return dp[i][j][moves] = 0;
    }
    if (dp[i][j][moves] != -1)
    {
        return dp[i][j][moves];
    }
    int ans = 0;
    ans = addMOD(rec(i, j + 1, moves + 1), rec(i + 1, j, 0));
    return dp[i][j][moves] = ans;
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int l = 0; l <= k; l++)
            {
                dp[i][j][l] = -1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << rec(0, 0, 0) << nline;
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