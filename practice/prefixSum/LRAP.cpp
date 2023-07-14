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
ll n, q, A, d, l, r;
ll a[1001001];
ll diff[1001001];
void solve()
{
    memset(a, 0, sizeof(a));
    memset(diff, 0, sizeof(diff));
    cin >> n >> q;
    while (q--)
    {
        cin >> A >> d >> l >> r;
        l--;
        r--;
        a[l] = addMOD(a[l], A);
        if (r + 1 < n)
            a[r + 1] = subMOD(a[r + 1], A);
        if (l + 1 < n)
            diff[l + 1] = addMOD(diff[l + 1], d);
        if (r + 1 < n)
            diff[r + 1] = subMOD(diff[r + 1], mulMOD((r - l + 1), d));
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << nline;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << diff[i] << " ";
    // }
    cout << nline;
    for (int i = 1; i < n; i++)
        a[i] = addMOD(a[i], a[i - 1]);
    for (int i = 1; i < n; i++)
        diff[i] = addMOD(diff[i], diff[i - 1]);
    for (int i = 1; i < n; i++)
        diff[i] = addMOD(diff[i], diff[i - 1]);
    for (int i = 0; i < n; i++)
    {
        cout << addMOD(a[i], diff[i]) << " ";
    }
}
// void solve()
// {
//     memset(a, 0, sizeof(a));
//     memset(diff, 0, sizeof(diff));
//     cin >> n >> q;
//     while (q--)
//     {
//         cin >> A >> d >> l >> r;
//         l--;
//         r--;
//         a[l] += A;
//         if (r + 1 < n)
//             a[r + 1] -= A;
//         if (l + 1 < n)
//             diff[l + 1] += d;
//         if (r + 1 < n)
//             diff[r + 1] -= (r - l) * d;
//     }
//     for (int i = 0; i < n; i++)
//         cout << diff[i] << " ";
//     cout << nline;
//     for (int i = 0; i < n; i++)
//         cout << a[i] << " ";
//     cout << nline;
//     for (int i = 1; i < n; i++)
//         a[i] += a[i - 1];
//     for (int i = 1; i < n; i++)
//         diff[i] += diff[i - 1];
//     for (int i = 1; i < n; i++)
//         diff[i] += diff[i - 1];
//     for (int i = 0; i < n; i++)
//     {
//         cout << a[i] + diff[i] << " ";
//     }
// }
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
    while (t--)
    {
        solve();
    }
    return 0;
}