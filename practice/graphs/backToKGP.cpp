#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ppii=pair<pair<int,int>,pair<int,int>>;
using ii=pair<int,int>;
#define ff first
#define ss second
int m,n;
const int MOD=1e9+7;
vector<vector<ii>>g;
vector<int>visited;
vector<ppii>dist;//{dist,count,maxNode,minNode}
// vector<int>path;
// vector<int>parent;
void dijkstra(int start){
	priority_queue<ii,vector<ii>,greater<ii>>pq;
	dist.assign(n+1,{{1e18,0},{-1e18,1e18}});
	// parent.assign(n+1,-1);
	visited.assign(n+1,0);
	dist[start]={{0,1},{1,1}};
	pq.push({dist[start].ff.ff,start});
	while(!pq.empty()){
		ii curr=pq.top();
		pq.pop();
		int node=curr.ss;
		ppii currD=dist[node];
		if(visited[node])continue;
		visited[node]=1;
		for(auto nbrs:g[node]){
			int nbrsNode=nbrs.ff;
			int weight=nbrs.ss;
			if(dist[nbrsNode].ff.ff>currD.ff.ff+weight){
				dist[nbrsNode]={{currD.ff.ff+weight,currD.ff.ss},{currD.ss.ff+1,currD.ss.ss+1}};
				pq.push({dist[nbrsNode].ff.ff,nbrsNode});
				// parent[nbrsNode]=nbrsNode;
			}else if(dist[nbrsNode].ff.ff==currD.ff.ff+weight){
				dist[nbrsNode].ff.ss=(dist[nbrsNode].ff.ss%MOD+dist[node].ff.ss%MOD)%MOD;//adding the count of paths
				dist[nbrsNode].ss.ff=max(dist[nbrsNode].ss.ff,dist[node].ss.ff+1);//max node update
				dist[nbrsNode].ss.ss=min(dist[nbrsNode].ss.ss,dist[node].ss.ss+1);////min node update
			}
		}
	}
}
void solve(){
	cin>>n>>m;
	g.resize(n+1);
	for(int i=0;i<m;i++){
		int a,b,x;cin>>a>>b>>x;
		g[a].push_back({b,x});
	}
	dijkstra(1);
	// for(int i=1;i<=n;i++){
	// 	cout<<dist[i].ff.ff<<" "<<dist[i].ff.ss<<" "<<dist[i].ss.ss-1<<" "<<dist[i].ss.ff-1<<nline;
	// }
	if(dist[n].ff.ff==1e18){
		cout<<-1<<nline;
		return;
	}
	cout<<dist[n].ff.ff<<" "<<dist[n].ff.ss<<" "<<dist[n].ss.ss-1<<" "<<dist[n].ss.ff-1<<nline;
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