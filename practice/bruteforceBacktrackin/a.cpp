#include <bits/stdc++.h>
using namespace std;
#define nline '\n'
#define ff first
#define ss second
void solve()
{
    int n;
    cin >> n;
    pair<string, pair<int, int>> ada[1010];
    pair<pair<int, int>, string> charles[1010];
    string c;
    int d, u;
    for (int i = 0; i < n; i++)
    {
        cin >> c >> d >> u;
        ada[i].ff = c;
        ada[i].ss.ff = u;
        ada[i].ss.ss = d;
        charles[i].ff = d;
        charles[i].ss.ff = u;
        charles[i].ss.ss = c;
    }
    sort(ada, ada + n);
    sort(charles, charles + n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (ada[i] == charles[i])
            count++;
    }
    cout << count << nline;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}