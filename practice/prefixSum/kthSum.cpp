#include <bits/stdc++.h>
#include <iterator>
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
bool check(ll x, vector<pair<ll, ll>> v, ll k)
{
    return v[x].ss >= k;
}
void solve()
{
    ll n, m, q;
    cin >> n >> m >> q;
    vll A(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vll present(n, 0);
    ll l, r;
    while (m--)
    {
        cin >> l >> r;
        l--;
        r--;
        present[l]++;
        if (r + 1 < n)
            present[r + 1]--;
    }
    for (int i = 1; i < n; i++)
    {
        present[i] += present[i - 1];
    }
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = {A[i], present[i]};
    }
    sort(v.begin(), v.end());
    vector<pair<ll, ll>> queries(q);
    for (int i = 0; i < q; i++)
    {
        ll k;
        cin >> k;
        k;
        queries[i].ff = k;
        queries[i].ss = i;
    }
    sort(queries.begin(), queries.end());
    int j = 0;
    ll remaining = 0;
    vector<int> sol(q);
    for (int i = 0; i < q; i++)
    {
        while (j < n && remaining + v[j].ss < queries[i].ff)
        {

            remaining += v[j].ss;
            j++;
        }
        if (j < n)
        {
            sol[queries[i].ss] = v[j].ff;
        }
        else
        {
            sol[queries[i].ss] = -1;
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << sol[i] << " ";
    }
    cout << nline;
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