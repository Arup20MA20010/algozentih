#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using pii=pair<pair<int,int>,int>;
#define ff first
#define ss second
vector<pii>edgeList;
vector<int>dist;
void solve(){
	int m,n;cin>>n>>m;
	dist.assign(n+1,-1e18);
	for(int i=0;i<m;i++){
		int a,b,x;cin>>a>>b>>x;
		edgeList.push_back({{a,b},x});
	}
	dist[1]=0;
	for(int i=0;i<n;i++){
		for(auto edge:edgeList){
			int weight=edge.ss;
			int node=edge.ff.ff;
			int nbr=edge.ff.ss;
			if(dist[nbr]<dist[node]+weight){
				dist[nbr]=dist[node]+weight;
			}
		}
	}
	int flag=0;
	for(auto edge:edgeList){
		int weight=edge.ss;
		int node=edge.ff.ff;
		int nbr=edge.ff.ss;
		if(dist[nbr]<dist[node]+weight){
			flag=1;
			break;
		}
	}
	if(flag){cout<<-1<<nline;return;}
	cout<<dist[n]<<nline;
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