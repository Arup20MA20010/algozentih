#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'

void solve()
{
    int dp[51][51];
    int val[51][51];
    int arr[51];
    int n,x, y, z;
    cin>>n>>x>>y>>z;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        val[i][i]=arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int ans=0;int maxVal=0;
            for(int k=i;k<j;k++){
                if(ans>dp[i][k]+dp[k+1][j]+val[i][k]*val[k+1][j]){
                    ans=dp[i][k]+dp[k+1][j]+val[i][k]*val[k+1][j];
                    maxVal=(val[i][k]*x+val[k+1][j]*y+z)%50;
                }
            }
            dp[i][j]=ans;
            val[i][j]=maxVal;
        }
    }
    cout<<dp[0][n-1]<<nline;
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