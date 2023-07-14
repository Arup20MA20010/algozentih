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
int n;
vector<int> v;
map<int, int> mp;
vector<int> prefix;
void solve()
{
    cin >> n;
    v.resize(n);
    prefix.reserve(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    prefix = v;
    for (int i = 1; i < n; i++)
    {
        prefix[i] = (prefix[i] % n + prefix[i - 1] % n) % n;
    }
    mp[0] = -1;
    // single solution
    for (int i = 0; i < n; i++)
    {
        if (mp.find(prefix[i]) != mp.end())
        {
            // solution prefix[i]+1,i
            for (int j = mp[prefix[i]] + 1; j <= i; j++)
            {
                cout << v[j] << " ";
            }
            break;
        }
        mp[prefix[i]] = i;
    }
    cout << nline;
    // no. of solution
    mp.clear();
    mp[0] = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += mp[prefix[i]];
        mp[prefix[i]]++;
    }
    cout << ans << nline;
    // print all subarray
    map<int, vector<int>> m;
    m[0].push_back(-1);
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto x : m[prefix[i]])
        {
            // solution from v+1,i
            for (int j = x + 1; j <= i; j++)
            {
                cout << v[j] << " ";
            }
            cout << nline;
        }
        ans += m[prefix[i]].size();
        m[prefix[i]].push_back(i);
    }
    cout << ans << nline;
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