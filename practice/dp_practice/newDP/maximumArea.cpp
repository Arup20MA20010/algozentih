#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[201][201];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int c1 = 0; c1 < m; c1++)
    {
        vector<int> rowSum(n, 0);
        for (int c2 = c1; c2 < m; c2++)
        {
            int l = 0;
            for (int r = 0; r < n; r++)
            {
                rowSum[r] += arr[r][c2];
                if (rowSum[r] == (c2 - c1 + 1))
                {
                    l++;
                    ans = max(ans, l * (c2 - c1 + 1));
                }
                else
                {
                    l = 0;
                }
            }
        }
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
    while (t--)
    {
        solve();
    }
    return 0;
}