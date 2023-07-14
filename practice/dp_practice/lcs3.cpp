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
template <typename T>
class monotone_dequeue
{
public:
    deque<T> dq;
    void insert(T x)
    {
        while (!dq.empty() && x < dq.back())
        {
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void remove(int x)
    {
        if (dq.front() == x)
        {
            dq.pop_front();
        }
    }
    T getMin()
    {
        if (!dq.empty())
        {
            return dq.front();
        }
    }
};
int n, m, k;
int dp[101][101][101];
string s1, s2, s3;
int rec(int level1, int level2, int level3)
{
    if (level1 == n || level2 == m || level3 == k)
    {
        return 0;
    }
    if (dp[level1][level2][level3] != -1)
    {
        return dp[level1][level2][level3];
    }
    if (s1[level1] == s2[level2] && s2[level2] == s3[level3])
    {
        return dp[level1][level2][level3] = 1 + rec(level1 + 1, level2 + 1, level3 + 1);
    }
    int ans1 = rec(level1, level2, level3 + 1);
    int ans2 = rec(level1, level2 + 1, level3);
    int ans3 = rec(level1 + 1, level2, level3);
    return dp[level1][level2][level3] = max(ans1, max(ans2, ans3));
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> s1 >> s2 >> s3;
    n = s1.length();
    m = s2.length();
    k = s3.length();
    cout << rec(0, 0, 0) << nline;
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