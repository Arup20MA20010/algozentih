// to check if there exist and array with subsequence sum == T
// we take the state i and S where i is the element to which we have processed and S is the sum till now. So dp(i,S) denotes if the we can find the subset of elements taken from a[0...i] whose sum if S, hence we need to find dp(n-1,T).
// So for the position i we we have two choices, either to include it or to exclude it. So if we include it we get dp(i-1,S-a[i]) as the answer to wether the sum exist or not. Simlarly if we exclude the element we get dp(i-1,S) as the answer. Now if in either case the answer exist then we say that the answer exist, so we need to get dp(i,S)=dp(i-1,S-a[i])||dp(i-1,S).
// It is given that all the elements are >=0.
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
const int N = 100100;
int n;
int dp[N][N];
int a[N];
int T;
int ifExist(int level, int s)
{
    if (s < 0)
    {
        return 0;
    }
    if (s == 0)
    {
        return 1;
    }
    if (level < 0)
    {
        return 0;
    }
    // if computed
    if (dp[level][s] != -1)
        return dp[level][s];
    return dp[level][s] = ifExist(level - 1, s - a[level]) || ifExist(level - 1, s);
}
void solve()
{
    cin >> n >> T;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(dp, -1, sizeof(dp));
    if (ifExist(n - 1, T))
        cout << "YES" << nline;
    else
        cout << "NO" << nline;
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