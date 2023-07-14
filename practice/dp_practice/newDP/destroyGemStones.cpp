#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;
int s[101];
int dp[101][101];
int rec(int l,int r){
    if(l>r){
        return 0;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    int ans=1+rec(l+1,r);
    if(l+1<=r&&s[l]==s[l+1]){
        ans=min(ans,1+rec(l+2,r));
    }
    for(int x=l+2;x<=r;x++){
        if(s[x]==s[l]){
            ans=min(ans,rec(l+1,x-1)+rec(x+1,r));
        }
    }
    return dp[l][r]=ans;
}
void solve(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    cout<<rec(0,n-1)<<nline;
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