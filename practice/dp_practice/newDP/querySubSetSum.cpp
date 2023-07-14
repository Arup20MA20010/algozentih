#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool dp[101][100100];
bool computed[101][100100];
bool rec(int level, int remSum, vector<int> &arr, vector<int> &ans)
{
    if (level <= arr.size() && remSum == 0)
    {
        return true;
    }
    if (level == arr.size() && remSum != 0 || remSum < 0)
    {
        return false;
    }
    if (computed[level][remSum])
    {
        return dp[level][remSum];
    }
    computed[level][remSum] = true;
    ans.push_back(level);
    if (rec(level + 1, remSum - arr[level], arr, ans))
    {
        return dp[level][remSum] = true;
    }
    ans.pop_back();
    return dp[level][remSum] = rec(level + 1, remSum, arr, ans);
}
vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries)
{
    // Write code here.
    vector<vector<int>> res;
    vector<int> ans;
    for (auto q : queries)
    {
        if (rec(0, q, arr, ans))
        {
            res.push_back(ans);
            ans.clear();
        }
        else
        {
            res.push_back({-1});
        }
    }
    for (auto v : res)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return res;
}

void solve()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)
        cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q)
    {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++)
    {
        auto x = ans[i];
        if (x.size() == 0)
        {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1)
        {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x)
        {
            if (y < 0 || y >= N || p >= y)
            { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i])
        {
            cout << 1 << endl;
        }
        else
            cout << 101 << endl;
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}