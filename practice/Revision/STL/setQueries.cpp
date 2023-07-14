#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
    int q;cin>>q;
    set<int>s;
    set<int>ns;
    while(q--){
        int t;cin>>t;
        int x;cin>>x;
        if(t==1){
            s.insert(x);
            ns.erase(x);
            if(s.find(x+1)==s.end()){
                ns.insert(x+1);
            }
        }else{
            if(s.find(x)==s.end()){
                cout<<x<<nline;
            }else{
                auto it=lower_bound(ns.begin(),ns.end(),x);
                cout<<*it<<nline;
            }
        }
    }
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
}