#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>visited;
vector<int>topo;
void dfs(int node){
	visited[node]=1;
	for(auto nbrs:g[node]){
		if(!visited[nbrs]){
			dfs(nbrs);
		}
	}
	topo.push_back(node);
}
void solve(){
	int m,n;cin>>n>>m;
	g.resize(n+1);
	visited.assign(n+1,0);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	reverse(topo.begin(),topo.end());
	for(auto v:topo){
		cout<<v<<" ";
	}
	cout<<nline;
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