#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[101][101][101];
int arr[101];
int rec(int l,int r,int x){
    if(l>r){
        return 0;
    }
    if(dp[l][r][x]!=-1){
        return dp[l][r][x];
    }
    //removing it then and there
    int ans=(x+1)*(x+1)+rec(l+1,r,0);
    for(int k=l+1;k<=r;k++){
        if(arr[k]==arr[l]){
            ans=max(ans,rec(l+1,k-1,0)+rec(k,r,x+1));
        }
    }
    return dp[l][r][x]=ans;
}
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1,0)<<nline;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    solve();
    return 0;
}