
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
#define MAXLEN 1000000
#define nline '\n'
void solve()
{
    ll n;
    ll p[MAXLEN + 1];
    for (int i = 0; i <= MAXLEN; i++)
    {
        p[i] = 0;
    }
    ll k, q;
    cin >> n >> k >> q;
    ll l, r;
    while (n--)
    {
        cin >> l >> r;
        p[l]++;
        if (r != MAXLEN)
            p[r + 1]--;
    }
    for (ll i = 1; i <= MAXLEN; i++)
    {
        p[i] += p[i - 1];
    }
    for (ll i = 1; i <= MAXLEN; i++)
    {
        p[i] = p[i] >= k ? 1 : 0;
        if (i != 1)
        {
            p[i] += p[i - 1];
        }
    }
    while (q--)
    {
        cin >> l >> r;
        ll high = p[r];
        ll low = l > 1 ? p[l - 1] : 0;
        cout << high - low << nline;
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
    // cin>> t;
    while (t--)
    {
        solve();
    }
    return 0;
}