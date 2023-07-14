#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;
int dp[100100][4];
int cost[100100];
string s;
char lookUp[] = {'h', 'a', 'r', 'd'};
int rec(int level, int state)
{
    if (state == 4)
    {
        return 1e18;
    }
    if (level == n)
    {
        return 0;
    }
    if (dp[level][state] != -1)
    {
        return dp[level][state];
    }
    int ans = 0;
    if (s[level] == lookUp[state])
    {
        ans = min(rec(level + 1, state + 1), rec(level + 1, state) + cost[level]);
    }
    else
    {
        ans = rec(level + 1, state);
    }
    return dp[level][state] = ans;
}
void solve()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
        for (int state = 0; state < 4; state++)
        {
            dp[i][state] = -1;
        }
    }
    cout << rec(0, 0) << nline;
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