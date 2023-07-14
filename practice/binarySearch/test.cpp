#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nline '\n'
int n, k;
ll arr[100100];
bool check(ll d)
{
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += ((arr[i] - arr[i - 1]) / d) - 1;
    }
    return ans <= k;
}
void solve()
{
    cin >> n >> k;
    cin >> arr[0];
    ll lo = 1, hi = 1;
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        hi = max(hi, arr[i] - arr[i - 1]);
    }
    ll ans = 0;
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
    cout << ans << nline;
}
int main()
{
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