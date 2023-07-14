#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int a[1001001];
int b[1001001];
int c[1001001];
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        c[i] = a[i] - b[i];
    }
    sort(c, c + n);
    int i = 0, j = n - 1;
    int cnt = 0;
    while (i < j)
    {
        if (c[i] + c[j] > 0)
        {
            cnt += j - i;
            j--;
        }
        else
        {
            i++;
        }
    }
    cout << cnt << nline;
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