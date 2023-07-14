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
char andOp(char leftExp, char rightExp)
{
    if (leftExp == '1' || rightExp == leftExp)
        return rightExp;
    if (rightExp == '1')
        return leftExp;
    if (leftExp == '0' || rightExp == '0')
        return '0';
    if (leftExp != rightExp)
        return '0';
}
char orOp(char leftExp, char rightExp)
{
    if (leftExp == '0' || rightExp == leftExp)
        return rightExp;
    if (rightExp == '0')
        return leftExp;
    if (leftExp == '1' || rightExp == '1')
        return '1';
    if (rightExp != leftExp)
        return '1';
}
char xorOp(char leftExp, char rightExp, char complement)
{
    if (rightExp == leftExp)
        return '0';
    if (rightExp == '0')
        return leftExp;
    if (leftExp == '0')
        return rightExp;
    if (rightExp == '1' || leftExp == '1')
        return complement;
    if (leftExp != rightExp)
        return '1';
}
void solve()
{
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            char rightExp = st.top();
            st.pop();
            char op = st.top();
            st.pop();
            char leftExp = st.top();
            st.pop();
            st.pop();
            if (op == '&')
            {
                st.push(andOp(leftExp, rightExp));
            }
            else if (op == '|')
            {
                st.push(orOp(leftExp, rightExp));
            }
            else
            {
                char complement = '0';
                if (leftExp == 'x')
                    complement = 'X';
                else if (rightExp == 'x')
                    complement = 'X';
                else if (leftExp == 'X')
                    complement = 'x';
                else if (rightExp == 'X')
                    complement = 'x';
                st.push(xorOp(leftExp, rightExp, complement));
            }
        }
        else
        {
            st.push(s[i]);
        }
    }
    if (st.top() == '1' || st.top() == '0')
        cout << 0 << nline;
    else
    {
        cout << 1 << nline;
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