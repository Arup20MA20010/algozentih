#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
string s;
int dp[101][101][27];
bool isComputed[101][101][27];
int n, m, k;
int cost[27][27];
int rec(int level, int moves, int state)
{
    // pruning
    if (moves < 0)
    {
        return -1e18;
    }
    // base condition
    if (level == n)
    {
        return 0;
    }
    // cache check
    if (isComputed[level][moves][state])
    {
        return dp[level][moves][state];
    }
    // transtion
    int ans = rec(level + 1, moves, (s[level] - 'a' + 1)) + cost[state][s[level] - 'a' + 1];
    for (int currState = 1; currState <= 26; currState++)
    {
        if (currState != (s[level] - 'a' + 1))
        {
            ans = max(rec(level + 1, moves - 1, currState) + cost[state][currState], ans);
        }
    }
    // save and return
    isComputed[level][moves][state] = true;
    return dp[level][moves][state] = ans;
}
void solve()
{
    cin >> s;
    n = s.length();
    cin >> k;
    cin >> m;
    char x, y;
    memset(cost, 0, sizeof(cost));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int l = 0; l <= 26; l++)
            {
                isComputed[i][j][l] = false;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        cin >> cost[x - 'a' + 1][y - 'a' + 1];
    }
    cout << rec(0, k, 0) << nline;
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