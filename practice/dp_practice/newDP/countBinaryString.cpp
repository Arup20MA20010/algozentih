#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
#define MOD 1000000007
int dp[1001001][4];
int addMOD(int a, int b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}
int rec(int level, int state)
{
    if (level == 0)
    {
        return 1;
    }
    if (dp[level][state] != -1)
    {
        return dp[level][state];
    }
    int ans = 0;
    if (state == 0)
    {
        ans = addMOD(rec(level - 1, 0), rec(level - 1, 1));
    }
    else if (state == 1)
    {
        ans = addMOD(rec(level - 1, 1), rec(level - 1, 2));
    }
    else if (state == 2)
    {
        ans = addMOD(rec(level - 1, 0), rec(level - 1, 3));
    }
    else
    {
        ans = rec(level - 1, 2) % MOD;
    }

    return dp[level][state] = ans;
}
void solve(int t)
{
    int n = t;
    cout << rec(n, 0) << nline;
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
    memset(dp, -1, sizeof(dp));
    for (int i = t; i > 0; i--)
    {
        solve(i);
    }
    return 0;
}