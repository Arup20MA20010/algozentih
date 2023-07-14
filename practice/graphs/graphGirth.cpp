#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
vector<ii>edgeList;
vector<int>dist;
vector<int>newDist;
void solve(){
	int n,m;cin>>n>>m;
	dist.assign(n+1,0);
	newDist.assign(n+1,0);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		edgeList.push_back({a,b});
		// edgeList.push_back({b,a});
	}
	for(int i=0;i<n;i++){
		for(auto edge:edgeList){
			int start=edge.ff;
			int end=edge.ss;
			if(dist[end]<dist[start]+1){
				dist[end]=dist[start]+1;//relaxing condtion
			}
		}
	}
	int ans=1e18;
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" ";
	}
	cout<<nline;
	for(auto edge:edgeList){
		int start=edge.ff;
		int end=edge.ss;
		if(dist[end]<dist[start]+1){
			newDist[end]=dist[start]+1;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" "<<newDist[i]<<nline;
	}
	cout<<nline;
	if(ans==1e18){
		cout<<-1<<nline;return;
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
	solve();
	return 0;
}