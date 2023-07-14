#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
#define MOD 1000000007
int a[1001001],b[1001001];
void precompute(){
    a[1]=1;
    b[1]=1;
    for(int i=2;i<=1e6;i++){
        a[i]=((2*a[i-1])%MOD+b[i-1]%MOD)%MOD;
        b[i]=((4*b[i-1])%MOD+(a[i-1])%MOD)%MOD;
    }
}
void solve(){
    int n;
    cin>>n;
    cout<<(a[n]%MOD+b[n]%MOD)%MOD<<nline;
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
    precompute();
    while(t--){
        solve();
    }
    return 0;
}