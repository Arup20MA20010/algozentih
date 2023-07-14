#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
    int n,x;cin>>n>>x;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int j=30;j>=0;j--){
        vector<int>bitSet;
        for(auto x:arr){
            if((x>>j)&1){
                bitSet.push_back(x);
            }
        }
        if(bitSet.size()>=x){
            ans+=(1<<j);
            arr=bitSet;
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