#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void bin(int n){
    for(int i=63;i>=0;i--){
        if(n&(1LL<<i)){
            cout<<1;
        }else{
            cout<<0;
        }
    }
}
int leftPos(int n){
    if(n==0){
        return -1;
    }
    int xl=__builtin_clzll(n);
    return 64-xl-1;
}
int rightPos(int n){
    if(n==0){
        return -1;
    }
    int xr=__builtin_ctzll(n);
    return xr;
}
int ifPowerOf2(int n){
    if(n>1&&((n&(n-1))==0)){
        return 1;
    }
    return 0;
}
int biggestPowerOf2(int n){
    if(n==0){
        return -1;
    }
    int ans=n;
    if(n<0){
        ans=(~n)+1;
    }
    if(ans>1&&((ans&(ans-1))==0)){
        return ans;
    }
    int rz=rightPos(ans);
    return (1<<rz);
}
int smallestPowerOf2(int n){
    if(n<=0){
        return 2;
    }
    if(n>1&&((n&(n-1))==0)){
        return n;
    }
    int lz=leftPos(n);
    return 1<<(lz+1);
}
void solve(){
    int n;cin>>n;
    bin(n);
    cout<<nline;
    cout<<leftPos(n)<<nline;
    cout<<rightPos(n)<<nline;
    cout<<ifPowerOf2(n)<<nline;
    cout<<biggestPowerOf2(n)<<nline;
    cout<<smallestPowerOf2(n)<<nline;
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