
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
#define nline '\n'
#define MOD 1000000007
void solve()
{
    int n, m, q;
    cin >> m >> n >> q;
    vector<vector<ll>> v(m, vector<ll>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int i = 1; i < m; i++)
    {
        v[i][0] += v[i - 1][0];
    }
    for (int j = 1; j < n; j++)
    {
        v[0][j] += v[0][j - 1];
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            v[i][j] += (v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1]);
        }
    }
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        ll ans = (v[x2][y2] - (x1 > 0 ? v[x1 - 1][y2] : 0) - (y1 > 0 ? v[x2][y1 - 1] : 0) + (x1 > 0 && y1 > 0 ? v[x1 - 1][y1 - 1] : 0));
        cout << (ans >= 0 ? ans % MOD : MOD + ans % MOD) << nline;
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
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}