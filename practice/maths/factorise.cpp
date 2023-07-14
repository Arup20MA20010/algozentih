#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nline '\n'
#define ff first
#define ss second
ll n;
pair<vector<ll>, vector<ll>> factorise()
{
    vector<ll> smaller;
    vector<ll> larger;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            smaller.push_back(i);
            if (n / i != i)
            {
                larger.push_back(n / i);
            }
        }
    }
    return {smaller, larger};
}
int main()
{
    cin >> n;
    auto ans = factorise();
    for (auto x : ans.ff)
    {
        cout << x << " ";
    }
    reverse(ans.ss.begin(), ans.ss.end());
    for (auto x : ans.ss)
    {
        cout << x << " ";
    }
    cout << nline;
    return 0;
}