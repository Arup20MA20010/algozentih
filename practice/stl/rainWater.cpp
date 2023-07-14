/**
 * for a given range the maximum height in the left would be h
 * so for each index the water stored = (h-hi)
 * right[i] is the index of the height of the first bar >=h[i] in the right side
 * left[i] is the index of the height of the left bar >=h[i] in the left side
 * ans+=max(h[left[i]],h[right[i]])-h[i]
 */
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
int n;
int h[100100];
int leftIndex[100100];
int rightIndex[100100];
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        leftIndex[i] = i - 1;
        rightIndex[i] = i + 1;
    }
    // filling the left side
    for (int i = 0; i < n; i++)
    {
        while (leftIndex[i] >= 0 && h[leftIndex[i]] <= h[i])
        {
            leftIndex[i] = leftIndex[leftIndex[i]];
        }
    }
    // filling the right side
    for (int i = n - 1; i >= 0; i--)
    {
        while (rightIndex[i] < n && h[rightIndex[i]] <= h[i])
        {
            rightIndex[i] = rightIndex[rightIndex[i]];
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << leftIndex[i] << " ";
    // }
    // cout << nline;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << rightIndex[i] << " ";
    // }
    // cout << nline;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (rightIndex[i] < n && leftIndex[i] >= 0)
        {
            ans += min(h[rightIndex[i]], h[leftIndex[i]]) - h[i];
        }
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