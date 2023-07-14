#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>visited;
void dfs(int node ,int cmp){
    visited[node]=cmp;
    for(auto nbrs:g[node]){
        if(!visited[nbrs]){
            dfs(nbrs,cmp);
        }
    }
}
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    g.resize(n+1);
    visited.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cmp=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cmp++;
            dfs(i,cmp);
        }
    }
    vector<int>noOfComponents(cmp+1,0);
    for(int i=1;i<=n;i++){
        noOfComponents[visited[i]]++;
    }
    while(q--){
        int x,y;cin>>x>>y;
        if(x==1){
            cout<<noOfComponents[visited[y]]<<nline;
        }else{
            int z;cin>>z;
            if(visited[y]==visited[z]){
                cout<<"YES"<<nline;
            }else{
                cout<<"NO"<<nline;
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
    solve();
    return 0;
}