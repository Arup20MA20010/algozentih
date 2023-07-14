#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
vector<vector<ii>>g;
vector<int>visted;
vector<int>dist;
int m,n;
//this algorithm doesn't work with negative cycles
void dijkstra(int node){
	priority_queue<ii,vector<ii>,greater<ii>>pq;
	dist.assign(n+1,1e18);
	pq.push({0,node});
	dist[node]=0;
	while(!pq.empty()){
		ii curr=pq.top();
		int currNode=curr.ss;
		if(visited[currNode])continue;
		visited[currNode]=1;
		for(auto nbrs:g[currNode]){
			int nbrsNode=nbrs.ff;
			int weight=nbrs.ss;
			if(dist[nbrsNode]>dist[currNode]+weight){
				dist[nbrsNode]=dist[currNode]+weight;
				//relaxing condition
				pq.push({dist[nbrsNode],nbrsNode});
			}
		}
	}
}
void solve(){
	cin>>n>>m;
	g.resize(n+1);
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	dijkstra();

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