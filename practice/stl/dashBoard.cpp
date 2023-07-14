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
template <typename T>
class dashBoard
{
    T sqSum = 0;
    T sum = 0;
    int size = 0;
    multiset<pair<int, T>> mt;
    map<T, int> freq;
    multiset<T> smaller;
    multiset<T> larger;

public:
    void balance()
    {
        if (larger.size() > smaller.size())
        {
            smaller.insert(*larger.begin());
            larger.erase(larger.find(*larger.begin()));
        }
        else if (smaller.size() - larger.size() == 2)
        {
            larger.insert(*smaller.rbegin());
            smaller.erase(smaller.find(*smaller.rbegin()));
        }
    }
    void insert(T x)
    {
        sqSum += x * x;
        size++;
        sum += x;
        if (mt.find({freq[x], x}) != mt.end())
        {
            mt.erase(mt.find({freq[x], x}));
        }
        freq[x]++;
        mt.insert({freq[x], x});
        if (smaller.empty())
        {
            smaller.insert(x);
            return;
        }
        if (x > *(smaller.rbegin()))
        {
            larger.insert(x);
        }
        else
        {
            smaller.insert(x);
        }
        /**
         * either x goes to smaller
         * or x goes to larger
         * if size(larger)>sizeof(smaller) means size(larger) and size(smaller) were equal. so take one from larger and insert into smaller
         * if size(smaller)-sizeof(larger)=2 take one from smaller and insert into larger
         */
        balance();
    }
    T getSum()
    {
        return sum;
    }
    T getMode()
    {
        return mt.rbegin()->ss;
    }
    double getMean()
    {
        return (double)sum / (1.0 * size);
    }
    double getVariance()
    {
        return (double)(sqSum / 1.0 * size) - getMean() * getMean();
    }
    double getMedian()
    {
        if (size & 1)
        {
            return *smaller.rbegin();
        }
        return (*smaller.rbegin() + *larger.begin()) / 2.0;
    }
    void remove(T x)
    {
        sqSum -= x * x;
        size--;
        sum -= x;
        if (mt.find(make_pair(freq[x], x)) != mt.end())
        {
            mt.erase(mt.find(make_pair(freq[x], x)));
        }
        freq[x]--;
        mt.insert(make_pair(freq[x], x));
        if (larger.find(x) != larger.end())
        {
            larger.erase(larger.find(x));
        }
        else if (smaller.find(x) != smaller.end())
        {
            smaller.erase(smaller.find(x));
        }
        /**
         * either x goes to smaller
         * or x goes to larger
         * if size(larger)>sizeof(smaller) means size(larger) and size(smaller) were equal. so take one from larger and insert into smaller
         * if size(smaller)-sizeof(larger)=2 take one from smaller and insert into larger
         */
        balance();
    }
};
void solve()
{
    dashBoard<int> db;
    int k;
    cin >> k;
    vector<int> v;
    while (k != -1)
    {
        db.insert(k);
        v.push_back(k);
        cout << "Mean: " << db.getMean() << nline;
        cout << "Variance: " << db.getVariance() << nline;
        cout << "Mode: " << db.getMode() << nline;
        cout << "Median: " << db.getMedian() << nline;
        cin >> k;
    }
    cout << "Now removing" << nline;
    for (auto x : v)
    {
        cout << x << " ";
    }
    for (auto x : v)
    {
        db.remove(x);
        cout << "Mean: " << db.getMean() << nline;
        cout << "Variance: " << db.getVariance() << nline;
        cout << "Mode: " << db.getMode() << nline;
        cout << "Median: " << db.getMedian() << nline;
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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}