#include<bits/stdc++.h>
using namespace std;
#define int long long
using ii=pair<int,int>;
#define nline '\n'
#define ff first
#define ss second
int m,n;
vector<vector<ii>g;
vector<int>dist;
void bfs01(int node){
	dist.assign(n+1,1e9);
	dist[node]=0;
	deque<int>dq;
	dq.push_back(node);
	while(!dq.empty()){
		int curr=dq.front();
		dq.pop_front();
		for(auto v:g[curr]){
			int nbrs=v.ff;
			int weight=s.ff;
			if(dist[nbrs]>dist[node]+weight){
				dist[nbrs]=dist[node]+weight;
				if(weight==0){
					dq.push_front(nbrs);
				}else{
					dq.push_back(nbrs);
				}
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
	bfs01(1);
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