#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int prevIndex[26];
void solve(){
    int n;cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<26;i++){
        prevIndex[i]=-1;
    }
    int ans=13*(n*(n+1));
    for(int i=0;i<n;i++){
        int k=i-prevIndex[s[i]-'a']-1;
        ans-=((k*(k+1))/2);
        prevIndex[s[i]-'a']=i;
    }
    for(int i=0;i<26;i++){
        int k=n-prevIndex[i]-1;
        ans-=((k*(k+1))/2);
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