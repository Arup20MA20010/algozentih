#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>visited;
void dfs(int node){
    visited[node]=1;//mark the node that is to be dfsed
    for(auto x:g[node]){
        if(!visited[x]){
            dfs(x);
        }
    }
}
void solve(){
    int m,n;cin>>m>>n;
    g.resize(n+1);
    visited.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
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
        g.clear();
        visited.clear();
    }
    return 0;
}