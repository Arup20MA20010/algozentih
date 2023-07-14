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
ll arr[100100];
ll distinct, sub_distinct;
void solve()
{
    ll n;
    cin >> n;
    vll v(n, 0);
    ll minlength = n;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        if (arr[v[i]] == 0)
        {
            distinct++;
        }
        arr[v[i]]++;
    }
    // cout << distinct << nline << nline << nline;
    ll tail = 0, head = -1;
    for (ll i = 0; i < n; i++)
        arr[v[i]] = 0;
    while (tail < n)
    {
        while (head + 1 < n && sub_distinct < distinct)
        {
            if (arr[v[head + 1]] == 0)
            {
                sub_distinct++;
            }
            head++;
            arr[v[head]]++;
        }
        if (distinct == sub_distinct)
        {
            minlength = min(minlength, head - tail + 1);
        }
        // debug
        // cout << tail << " " << head << " " << sub_distinct << nline;
        if (head >= tail)
        {
            if (arr[v[tail]] == 1)
                sub_distinct--;
            arr[v[tail]]--;
            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
        }
    }
    cout << minlength << nline;
    // cout << nline;
    // cout << nline;
    distinct = 0;
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