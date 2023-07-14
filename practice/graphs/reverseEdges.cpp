#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first 
#define ss second
vector<vector<ii>>g;
vector<int>dist;
int m,n;
// vector<int>path;
// vector<int>parent;
void BFS01(int node){
	dist.assign(n+1,1e18);
	// parent.assign(n+1,-1);
	deque<int>dq;
	dq.push_back(node);
	dist[node]=0;
	while(!dq.empty()){
		int curr=dq.front();
		dq.pop_front();
		for(auto nbrs:g[curr]){
			int nbrsNode=nbrs.ff;
			int weight=nbrs.ss;
			if(dist[curr]+weight<dist[nbrsNode]){
				dist[nbrsNode]=dist[curr]+weight;//relaxing condition
				if(weight==1){
					dq.push_back(nbrsNode);
				}else{
					dq.push_front(nbrsNode);
				}
				// parent[nbrsNode]=curr;
			}
		}
	}
}
void solve(){
	cin>>n>>m;
	g.resize(n+1);
	for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        if(a==b)continue;
        g[a].push_back({b,0});
        g[b].push_back({a,1});
    }
	BFS01(1);
    if(dist[n]==1e18){
        cout<<-1<<nline;
    }
	cout<<dist[n]<<nline;
	// int temp=n;
	// while(temp!=-1){
	// 	path.push_back(temp);
	// 	temp=parent[temp];
	// }
	// reverse(path.begin(),path.end());
	// for(auto v:path){
	// 	cout<<v<<" ";
	// }
	// cout<<parent[7]<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;cin>>t;
	while(t--){
		solve();
		g.clear();
		dist.clear();
	}
	return 0;
}