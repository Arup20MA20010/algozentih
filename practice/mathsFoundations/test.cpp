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
void solve(int num, int den)
{
    int sign = 1;
    string ans = "";
    if (num * den < 0)
    {
        if (num < 0)
        {
            num *= -1;
        }
        else
        {
            den *= -1;
        }
        sign = -1;
    }
    if (num < 0)
    {
        num *= -1;
    }
    if (den < 0)
    {
        den *= -1;
    }
    if (den == 1 || den == 2 || den == 4 || den == 8 || den == 16 || den == 64 || den == 5 || den == 10 || den == 25 || den == 50 || den == 100)
    {
        cout << sign * ((float)((num * 0.1) / (den * 0.1))) << nline;
        return;
    }
    bool flag = true;
    bool paren = false;
    int greater = 0;
    set<int> s;
    bool start = true;
    while (true)
    {
        if (abs(num) == 100 && abs(den) == 1)
        {
            return;
        }
        if (s.find(num / den) != s.end())
        {
            paren = true;
            break;
        }
        char ch = '0';
        if (num / den < 10)
        {
            ans += (ch + num / den);
        }
        else
        {
            int firstDigit = (num / den) / 10;
            int secondDigit = (num / den) % 10;
            ans += (ch + firstDigit);
            ans += (ch + secondDigit);
        }
        if (!start)
        {
            s.insert(num / den);
        }
        num = num % den;
        if (num == 0)
        {
            break;
        }
        if (10 * num >= den)
        {
            greater = 1;
        }
        else if (10 * num < den && 100 * num > den)
        {
            greater = 2;
        }
        if (flag)
        {
            ans += '.';
            flag = false;
        }
        if (greater == 1)
        {
            num = 10 * num;
            greater = 0;
        }
        if (greater == 2)
        {
            ans += '0';
            num = 100 * num;
            greater = 0;
        }
        start = false;
    }
    if (paren)
    {
        int i = 0, j = 0;
        while (ans[i] != '.')
        {
            i++;
        }
        i++;
        ans.insert(ans.begin() + i, '(');
        ans.insert(ans.end(), ')');
    }
    if (sign == -1)
    {
        ans.insert(ans.begin(), '-');
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
    /// int t;
    // cin >> t;
    int num, den;
    for (int i = 0; i <= 100; i++)
    {
        num = i;
        for (int j = 1; j <= 100; j++)
        {
            den = j;
            cout << "num=" << num << " den=" << den << " ";
            solve(num, den);
        }
    }
    return 0;
}