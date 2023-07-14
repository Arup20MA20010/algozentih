#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define nline '\n'
int n, m;
string s1, s2;
int dp[1002][1002];
int rec(int i, int j)
{
    if (i == n && j == m)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + rec(i + 1, j + 1);
    }
    int ans = 0;
    if (i < n && j < m)
    {
        ans = 1 + min(rec(i + 1, j), rec(i, j + 1));
    }
    else if (i < n)
    {
        ans = 1 + rec(i + 1, j);
    }
    else if (j < m)
    {
        ans = 1 + rec(i, j + 1);
    }
    return dp[i][j] = ans;
}
string ShortestCommonSupersequence(string &str1, string &str2)
{
    memset(dp, -1, sizeof(dp));
    s1 = str1;
    s2 = str2;
    n = s1.length();
    m = s2.length();
    int i = 0, j = 0;
    string ans;
    rec(0, 0);
    while (i < n && j < m)
    {
        if (s1[i] == s2[j])
        {
            ans.push_back(s1[i]);
            i++;
            j++;
        }
        else
        {
            if (dp[i + 1][j] <= dp[i][j + 1])
            {
                ans.push_back(s1[i]);
                i++;
            }
            else
            {
                ans.push_back(s2[j]);
                j++;
            }
        }
    }
    while (i < n)
    {
        ans.push_back(s1[i]);
        i++;
    }
    while (j < m)
    {
        ans.push_back(s2[j]);
        j++;
    }
    return ans;
}

void checker()
{
    string x, y;
    cin >> x >> y;
    auto s = ShortestCommonSupersequence(x, y);
    cout << s.size() << endl;
    bool f = 1;
    int i = 0, j = 0;
    while (i < x.size() && j < s.size())
    {
        if (x[i] == s[j])
            i++, j++;
        else
            j++;
    }
    if (i != x.size())
        f = 0;
    i = 0, j = 0;
    while (i < y.size() && j < s.size())
    {
        if (y[i] == s[j])
            i++, j++;
        else
            j++;
    }
    if (i != y.size())
        f = 0;
    cout << f << endl;
}
#undef int
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        checker();
        // i++;
    }
    return 0;
}