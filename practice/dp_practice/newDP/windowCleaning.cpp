#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int A[1001][1001];
int dp[1001][1001];
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int ch1 = -1;
            int ch2 = -1;
            if (j > 0)
            {
                ch1 = max(ch1, max(A[i - 1][j - 1], dp[i - 1][j - 1]));
            }
            if (j < m - 1)
            {
                ch2 = max(ch2, max(A[i - 1][j + 1], dp[i - 1][j + 1]));
            }
            dp[i][j] = max(max(ch1, ch2), max(dp[i - 1][j], A[i - 1][j]));
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << (dp[i][j] < A[i][j]);
        }
        cout << nline;
    }
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