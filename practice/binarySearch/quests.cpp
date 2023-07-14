/**
 * reversesort(a)
 * a1 a2 a3 a4 ... ak
 * so any k segments will allways have distinct elements.
 * c and d given;
 * to find the maximum k st i will get atleast c coins in d days
 * k is Infinite if i can cover c coins just by doing <=n quests without repeatation.
 * so sum(ai)>=c return INFINITE and d>max(i)
 * 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
 * k = [0,d]
 * check(x) if i can cover atleast c coins in <=d days if i cannot repeat till x days
 * a1 a2 a3 ...
 * find the no. of days it requires to cover c coins
 * if no. of days <=d return true;
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
ll n, c, d;
ll arr[100100];
bool check(ll x)
{
    ll cnt = 0;
    ll sum = 0;
    for (int i = 0; i <= x; i++)
        sum += arr[i];
    ll p = c / sum;
    ll r = c % sum;
    int i = 0;
    while (r > 0)
    {
        r -= arr[i];
        cnt++;
    }
    ll days = (x + 1) * p + cnt;
    return days <= d;
    /**
     * sum*p+r>=c;
     * r<sum
     * days to get till r=m
     * days = x*p+m
     */
}
void solve()
{
    cin >> n >> c >> d;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n, greater<int>());
    ll sum = 0;
    ll j = 0;
    while (sum < c && j < n)
    {
        sum += arr[j];
        j++;
    }
    if (sum >= c && j <= d)
    {
        cout << "Infinity" << nline;
        return;
    }
    ll ans = -1;
    ll hi = d, lo = 0;
    while (hi >= lo)
    {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    if (ans == -1)
    {
        cout << "Impossible" << nline;
        return;
    }
    cout << ans << nline;
    memset(arr, 0, sizeof(arr));
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