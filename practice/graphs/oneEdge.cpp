#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>visited;
void dfs(int node,int cmp){
    visited[node]=cmp;
    for(auto nbrs:g[node]){
        if(!visited[nbrs]){
            dfs(nbrs,cmp);
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
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
    vector<int>components(cmp+1,0);
    for(int i=1;i<=n;i++){
        components[visited[i]]++;
    }
    int sum=0;
    int ans=0;
    for(int i=1;i<=cmp;i++){
        ans+=sum*components[i];
        sum+=components[i];
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
    solve();
    return 0;
}