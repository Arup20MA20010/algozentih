#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
int m,n;
vector<vector<ii>>g;
vector<int>dist;
vector<int>marked;
void bfs(int st){
	priority_queue<ii>pq;
	dist.assign(n+1,1e18);
	marked.assign(n+1,0);
	dist[st]=0;
	pq.push({0,st});
	while(!pq.empty()){
		ii curr=pq.top();
		pq.pop();
		int node=curr.ss;
		if(marked[node])continue;
		marked[node]=1;

		for(auto nbrs:g[node]){//for all the nbrs of node
			int nbrsNode=nbrs.ff;
			int weight=nbrs.ss;
			if(dist[node]+weight<dist[nbrsNode]){
				dist[nbrsNode]=dist[node]+weight;//relaxing condition
				pq.push({-dist[nbrsNode],nbrsNode});
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
	}
	bfs(1);
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" ";
	}
	cout<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	solve();
	return 0;
}