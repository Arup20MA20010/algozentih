#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n, m, k;
int arr[102][102];
int dp[102][102][12];
int rec(int x, int y, int remSum)
{
    if (y < 0 || y >= m)
    {
        return -1e18;
    }
    if (x == -1)
    {
        if (remSum == 0)
        {
            return 0;
        }
        return -1e18;
    }
    if (dp[x][y][remSum] != -1)
    {
        return dp[x][y][remSum];
    }
    return dp[x][y][remSum] = max(rec(x - 1, y - 1, (remSum + arr[x][y]) % k), rec(x - 1, y + 1, (remSum + arr[x][y]) % k)) + arr[x][y];
}
void solve()
{
    cin >> n >> m >> k;
    char z;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> z;
            arr[i][j] = z - '0';
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = -1e18;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, rec(n - 1, i, 0));
    }
    cout << (ans > 0 ? ans : -1) << nline;
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
