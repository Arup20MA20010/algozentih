
#include <bits/stdc++.h>
#include <iterator>
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
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vi A(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vi present(n, 0);
    int l, r;
    while (m--)
    {
        cin >> l >> r;
        l--;
        r--;
        present[l]++;
        if (r + 1 < n)
            present[r + 1]--;
    }
    for (int i = 1; i < n; i++)
    {
        present[i] += present[i - 1];
    }
    vector<pair<int, int>> v(n);
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        v[i] = {A[i], present[i]};
        size += present[i];
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 1; i < n; i++)
    {
        v[i].second += v[i - 1].second;
    }

    while (q--)
    {
        int k;
        cin >> k;
        if (k > size)
        {
            cout << -1 << " ";
            continue;
        }
        auto it = lower_bound(v.begin(), v.end(), k, [](pair<int, int> a, int b) -> bool
                              { return a.ss < b; });
        int pos = it - v.begin();
        cout << v[pos].first << " ";
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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}