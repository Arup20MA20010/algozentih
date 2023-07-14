#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n, m;
int getMaxSumSubarray(vector<int> arr)
{
    int maxSum = 0;
    int sum = 0;
    int maxValue = -1e18;
    for (auto it = arr.begin(); it < arr.end(); it++)
    {
        sum += *it;
        maxSum = max(sum, maxSum);
        if (sum < 0)
        {
            sum = 0;
        }
        maxValue = max(*it, maxValue);
    }
    if (maxSum == 0)
    {
        return maxValue;
    }
    return maxSum;
}
// m<n
int getMaxSum(vector<vector<int>> arr, int n, int m)
{
    int ans = -1e18;
    for (int c1 = 0; c1 < m; c1++)
    {
        vector<int> rowSum(n, 0);
        for (int c2 = c1; c2 < m; c2++)
        {
            for (int row = 0; row < n; row++)
            {
                rowSum[row] += arr[row][c2];
            }
            ans = max(ans, getMaxSumSubarray(rowSum));
        }
    }
    return ans;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(max(m, n), vector<int>(min(m, n), 0));
    if (m < n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[j][i];
            }
        }
    }
    cout << getMaxSum(arr, max(m, n), min(m, n)) << nline;
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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}