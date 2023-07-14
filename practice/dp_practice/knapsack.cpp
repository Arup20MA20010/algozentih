
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define Eps INT_MIN
#define range(i, n)             \
    for (int i = 0; i < n; i++) \
        ;
#define fo(s, e) for (int i = s; i < e; i++)
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define ff first
#define ss second
#define vec vector
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define vpii vector<pair<int, int>>
#define vpil vector<pair<int, long long>>
#define vpll vector<pair<long long, long long>>
#define all(x) x.begin(), x.end()
#define pb push_back
int maxValues(int n, vector<int> v, vector<int> w, int W, int level, int *dp)
{
    {
        if (W < 0)
        {
            return INT_MIN;
        }
        if (dp[level] < 0)
        {
            dp[level] = 0;
            return 0;
        }
        if (dp[level] != 0)
        {
            return dp[level];
        }
        int max_value = 0;
        max_value = max(v[level] + maxValues(n, v, w, W - w[level], level - 1, dp), maxValues(n, v, w, W, level - 1, dp));
        return dp[level] = max_value;
    }
    void solve()
    {
        int n;
        cin >> n;
        int W;
        cin >> W;
        vector<int> values(n, 0);
        vector<int> weights(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> weights[i] >> values[i];
        }
    }
    int main()
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