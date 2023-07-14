#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>col;
bool isCycle;
vector<int>parent;
void dfs(int node,int par){
    col[node]=2;
    parent[node]=par;
    for(auto nbrs:g[node]){
        if(parent[node]==nbrs){
            continue;
        }
        if(col[nbrs]==1){
            dfs(nbrs,node);
        }else if(col[nbrs]==2){
           isCycle=1;
        }
    }
    col[node]=3;
}
void solve(){
    int m,n;cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1,1);
    parent.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(col[i]==1){
            dfs(i,0);
            if(isCycle){
                cout<<"YES"<<nline;
                return;
            }
        }
    }
    cout<<"NO"<<nline;
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
}