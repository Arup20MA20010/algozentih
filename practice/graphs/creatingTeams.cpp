#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>col;
bool isBipartite;
void dfs(int node,int flag){
    if(flag){
        col[node]=1;
    }else{
        col[node]=2;
    }
    for(auto nbrs:g[node]){
        if(col[nbrs]==0){
            dfs(nbrs,1-flag);
        }else if(col[nbrs]==col[node]){
            isBipartite=0;
        }
    }
}
void solve(){
    int n,m;cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    isBipartite=1;
    for(int i=1;i<=n;i++){
        if(col[i]==0){
            dfs(i,1);
        }
    }
    if(isBipartite){
        cout<<"YES"<<nline;
    }else{
        cout<<"NO"<<nline;
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
    solve();
    return 0;
}