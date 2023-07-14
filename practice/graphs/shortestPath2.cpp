#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>dist;
void solve(){
	int n,m,q;cin>>n>>m>>q;
	dist.assign(n+1,vector<int>(n+1,1e18));
	for(int i=1;i<=n;i++){
		dist[i][i]=0;
	}
	for(int i=0;i<m;i++){
		int a,b,x;cin>>a>>b>>x;
		dist[a][b]=min(dist[a][b],x);
		dist[b][a]=min(dist[b][a],x);
	}
	//floyd warshall algorithms
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		int a,b;cin>>a>>b;
		cout<<(dist[a][b]!=1e18?dist[a][b]:-1)<<nline;
	}

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