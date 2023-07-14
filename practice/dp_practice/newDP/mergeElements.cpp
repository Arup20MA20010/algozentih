#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;
int arr[530];
int dp[530][530]; // dp(l,r) minimum cost from l,r
int rec(int l, int r)
{
    if (l == r)
    {
        return 0;
    }
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    int ans = 1e9;
    int total = 0;
    int sum = 0;
    for (int i = l; i <= r; i++)
    {
        total += arr[i];
    }
    for (int k = l; k < r; k++)
    {
        sum += arr[k];
        ans = min(ans, rec(l, k) + rec(k + 1, r) + (sum % 100) * ((total - sum) % 100));
    }
    return dp[l][r] = ans;
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, n - 1) << nline;
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