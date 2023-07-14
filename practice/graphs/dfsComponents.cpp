#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>comp;
vector<pair<int,int>>edgeList;
void dfs(int node,int cmp){
    comp[node]=cmp;
    for(auto nbrs:g[node]){
        if(comp[nbrs]==0){
            dfs(node,cmp);
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    comp.assign(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        edgeList.push_back({x,y});
    }
    int cmp=0;
    for(int i=1;i<=n;i++){
        if(comp[i]==0){
            cmp++;
            dfs(i,cmp);
        }
    }
    vector<int>components(cmp+1);
    int sum=0;
    int ans=0;
    for(auto edge:edgeList){
        components[comp[edge.first]]++;
    }
    for(int i=1;i<=cmp;i++){
        ans+=sum*components[cmp];
        sum+=components[cmp];
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