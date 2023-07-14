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
ll factorials[100001] = {0};
ll power(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ((ans * (a % MOD)) % MOD + MOD) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
ll rem(ll a)
{
    return ((a % MOD) + MOD) % MOD;
}
ll addMOD(ll a, ll b)
{
    return ((a % MOD + b % MOD) % MOD + MOD) % MOD;
}
ll subMOD(ll a, ll b)
{
    return ((a % MOD - b % MOD) % MOD + MOD) % MOD;
}
ll mulMOD(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
ll inverseMOD(ll a)
{
    return rem(power(a, MOD - 2));
}
ll divideMOD(ll a, ll b)
{
    return mulMOD(a, inverseMOD(b));
}
ll gcd(ll a, ll b)
{
    if (a < b)
    {
        return gcd(b, a);
    }
    return b == 0 ? a : gcd(b, a % b);
}
void factorial()
{
    for (ll i = 1; i <= 100001; i++)
    {
        factorials[i] = mulMOD(factorials[i], i);
    }
}
ll ncr(ll n, ll r)
{
    return divideMOD(factorials[n], mulMOD(factorials[r], factorials[n - r]));
}
int n, q, l, r, z;
vector<pair<pair<int, int>, int>> v;
void solve()
{
    cin >> n >> q;
    for (int i = 0; i < n; i)
    {
        cin >> l >> r >> z;
        v.pb({{l, 0}, z});
        v.pb({{r, 2}, z});
    }
    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        v.pb({{x, 1}, i});
    }
    multiset<int> mt;
    sort(v.begin(), v.end());
    vector<pair<int, int>> ans;
    int min;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].ff.ss == 0)
        {
            // start
            mt.insert(v[i].ss);
        }
        else if (v[i].ff.ss == 1)
        {
            // query
            if (!mt.empty())
            {
                min = *(mt.rbegin());
                ans.pb({v[i].ss, min});
            }
        }
        else
        {
            // end
            mt.erase(mt.find(v[i].ss));
        }
    }
    sort(ans.begin(), ans.end());
    for (auto it : ans)
    {
        int minimum = it.ss;
        cout << minimum << nline;
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
    solve();
    return 0;
}