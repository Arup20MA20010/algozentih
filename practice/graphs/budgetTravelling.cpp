#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
using pii=pair<int,pair<int,int>>;
#define ff first
#define ss second
int n,m,C,d;
vector<vector<ii>>g;
vector<vector<int>>cost;
vector<vector<int>>visited;
vector<int>p;
// vector<vector<ii>>parent;
// vector<ii>path;
void dijkstra(ii start){
	cost.assign(n+1,vector<int>(C+1,1e9));
	visited.assign(n+1,vector<int>(C+1,0));
	// parent.assign(n+1,vector<ii>(C+1,{-1,-1}));
	cost[start.ff][start.ss]=0;
	priority_queue<pii,vector<pii>,greater<pii>>pq;//{dist,{node,petrol}}
	pq.push({cost[start.ff][start.ss],start});
	while(!pq.empty()){
		pii curr=pq.top();
		pq.pop();
		ii currNode=curr.ss;
		int node=currNode.ff;
		int petrol=currNode.ss;
		if(visited[node][petrol])continue;
		visited[node][petrol]=1;
		for(auto nbrs:g[node]){
			int nbrsNode=nbrs.ff;
			int nbrsDist=nbrs.ss;
			// if(nbrsDist<petrol)continue;
			for(int x=nbrsDist-petrol;x<=C+nbrsDist-petrol;x++){
				int weight=(x>0?p[node]*x:0);
				if(cost[nbrsNode][petrol+x-nbrsDist]>cost[node][petrol]+weight){
					cost[nbrsNode][petrol+x-nbrsDist]=cost[node][petrol]+weight;
					pq.push({cost[nbrsNode][petrol+x-nbrsDist],{nbrsNode,petrol+x-nbrsDist}});
					// parent[nbrsNode][petrol+x-nbrsDist]={node,petrol};
				}
			}
		}

	}
}
void solve(){
	cin>>n>>m;
	g.resize(n+1);
	p.resize(n+1);
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	int start,end;cin>>start>>end;
	cin>>C;
	dijkstra({start,0});
	int ans=1e18;
	int index=0;
	for(int i=0;i<=C;i++){
		if(ans>cost[end][i]){
			ans=cost[end][i];
			index=i;
		}
	}
	cout<<ans<<nline;
	// ii temp={end,index};
	// while(temp!=make_pair(-1LL,-1LL)){
	// 	path.push_back(temp);
	// 	temp=parent[temp.ff][temp.ss];
	// }
	// reverse(path.begin(),path.end());
	// for(auto state:path){
	// 	cout<<"( "<<state.ff<<" "<<state.ss<<") -->";
	// }
	// cout<<nline;
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