/**
 * Read the question carefully and observe the test cases
 * then recall the methods you have learn and try to fit the question into those approaches
 * try to bring a logical and mathematical solution
 * for optimisation type question try applying binary search
 * start with a brute force approach and then try to use all the information in the question that can be extracted to get optimise the approach
 * then debug
 */
// solution to the question
/**
 * Here we solve this question using the contribution method
 * we try to find the maximum segement for which an element is the minimum.for the given maximum segment the element is the minimum it is a potential answer for all the segments with length below the maximum range
 * so we build an answer array with maximum possible range as the index
 * now if k is the maximum range for two or more elements say a1 a2 ... ap
 * then ans[k]= max(a1,a2,a3,...,ap) as these elements will always compete with each other and maximum will always be the winner
 * Then we build a suffix array by taking into account the fact that any element which is a minimum for a given segment is also a potential candidate for the segments below it.
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
int arr[100100];
int leftIndex[100100];
int rightIndex[100100];
int ans[100100];
void solve()
{
    cin >> n;
    ans[n] = 0;
    for (int i = 0; i < n; i++)
    {
        ans[i] = 0;
        cin >> arr[i];
        leftIndex[i] = i - 1;
        rightIndex[i] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        while (leftIndex[i] >= 0 && arr[leftIndex[i]] > arr[i])
        {
            leftIndex[i] = leftIndex[leftIndex[i]];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (rightIndex[i] < n && arr[rightIndex[i]] >= arr[i])
        {
            rightIndex[i] = rightIndex[rightIndex[i]];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int x = rightIndex[i] - leftIndex[i] - 1;
        ans[x] = max(ans[x], arr[i]);
    }
    for (int i = n - 1; i > 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}