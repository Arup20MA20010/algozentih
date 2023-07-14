#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n, m;
string s1, s2;
int dp[1002][1002];
int rec(int i, int j)
{
    if (i == n && j == m)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + rec(i + 1, j + 1);
    }
    int ans = 0;
    if (i < n && j < m)
    {
        ans = 1 + min(rec(i + 1, j), rec(i, j + 1));
    }
    else if (i < n)
    {
        ans = 1 + rec(i + 1, j);
    }
    else if (j < m)
    {
        ans = 1 + rec(i, j + 1);
    }
    return dp[i][j] = ans;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    int i = 0, j = 0;
    string ans;
    rec(0, 0);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<nline;
    }
    while (i < n && j < m)
    {
        if (s1[i] == s2[j])
        {
            ans.push_back(s1[i]);
            i++;
            j++;
        }
        else
        {
            if (dp[i + 1][j] <= dp[i][j + 1])
            {
                ans.push_back(s1[i]);
                i++;
            }
            else
            {
                ans.push_back(s2[j]);
                j++;
            }
        }
    }
    while (i < n)
    {
        ans.push_back(s1[i]);
        i++;
    }
    while (j < m)
    {
        ans.push_back(s2[j]);
        j++;
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