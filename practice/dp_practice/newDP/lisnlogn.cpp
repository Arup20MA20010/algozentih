#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;
int arr[100100];
int dp[100100];
/*
store (len,lastElement)
len lis of lenght and len and lastElement.
*/
int lis(vector<int> arr)
{
    vector<int> temp;
    for (auto v : arr)
    {
        if (temp.empty() || v > temp.back())
        {
            temp.push_back(v);
        }
        else
        {
            auto it = lower_bound(temp.begin(), temp.end(), v);
            *it = v;
        }
    }
    return temp.size();
}
void solve()
{
    int n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << lis(v) << nline;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}