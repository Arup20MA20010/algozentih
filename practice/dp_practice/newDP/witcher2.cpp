#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int arr[201][201];
int dp[201][201];
int n,m,M;
bool check(int M){
    dp[0][0]=M+arr[0][0];
    if(dp[0][0]<=0){
        return false;
    }
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+arr[i][0];
        if(dp[i][0]<=0){
            dp[i][0]=-1e18;
        }
    }
    for(int j=1;j<m;j++){
        dp[0][j]=dp[0][j-1]+arr[0][j];
        if(dp[0][j]<=0){
            dp[0][j]=-1e18;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=max(dp[i-1][j]+arr[i][j],dp[i][j-1]+arr[i][j]);
            if(dp[i][j]<=0){
                dp[i][j]=-1e18;
            }
        }
    }
    return dp[n-1][m-1]>0;
}
void solve(){
    cin>>m>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<check(7)<<nline;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<nline;
    }
    int hi=1000*(m+n)+1,lo=1;
    int ans=-1;
    while(hi>=lo){
        int mid=lo+(hi-lo)/2;
        if(check(mid)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans<<nline;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}