#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>indeg;
vector<int>topo;
int m,n;
void kahn(){
	priority_queue<int,vector<int>,greater<int>>pq;
	for(int i=1;i<=n;i++){
		if(indeg[i]==0){
			pq.push(i);
		}
	}
	while(!pq.empty()){
		int curr=pq.top();
		pq.pop();
		topo.push_back(curr);
		for(auto nbrs:g[curr]){
			indeg[nbrs]--;
			if(indeg[nbrs]==0){
				pq.push(nbrs);
			}
		}
	}
}
void solve(){
	cin>>n>>m;
	g.resize(n+1);
	indeg.assign(n+1,0);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		indeg[b]++;
	}
	kahn();
	if(topo.size()!=n){
		cout<<-1<<nline;
		return;
	}
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