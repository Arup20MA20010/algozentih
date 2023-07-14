
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
    int n, q;
    cin >> n >> q;
    vector<ll> v(n, 0);
    cin >> v[0];
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        v[i] = (v[i] % MOD + (v[i - 1]) % MOD) % MOD;
    }
    vector<ll> prefixSum = v;
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = (prefixSum[i] % MOD + prefixSum[i - 1] % MOD) % MOD;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        ll ans = (r + 1 - l) * v[r] - ((r > 0 ? prefixSum[r - 1] : 0) - (l > 1 ? prefixSum[l - 2] : 0));
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