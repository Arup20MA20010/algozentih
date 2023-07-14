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
int factorial[17];
void solve()
{
    int n, k;
    vector<int> ans;

    cin >> n >> k;
    // there are two cases one for n>13 and second for n<=13
    set<int> v;
    if (n <= 13)
    {
        for (int i = 1; i <= n; i++)
        {
            v.insert(i);
        }
    }
    else
    {
        for (int i = 1; i <= n - 13; i++)
        {
            cout << i << " ";
        }
        for (int i = n - 12; i <= n; i++)
        {
            v.insert(i);
        }
    }
    int taken;
    int level = 1;
    if (n > 13)
    {
        level = n - 12;
    }
    while (level <= n)
    {
        int rank = k / factorial[n - level];
        if (k % factorial[n - level])
        {
            rank++;
            k = k % factorial[n - level];
        }
        else
        {
            k = factorial[n - level];
        }
        int pos = 1;
        for (auto x : v)
        {
            if (pos == rank)
            {
                taken = x;
                break;
            }
            pos++;
        }
        v.erase(taken);
        ans.push_back(taken);
        level++;
    }
    for (auto x : ans)
    {
        cout << x << " ";
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
    factorial[0] = 1;
    for (int i = 1; i < 17; i++)
    {
        factorial[i] = i * factorial[i - 1];
    }
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}