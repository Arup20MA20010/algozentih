#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;
int arr[200100];
int a,b;
int check(int i){
	if(i<1||i>=n)return 0;
	return 1;
}
vector<int>dist;
vector<int>pos[101];
vector<int>visited;
int dx[]={-1,1};
void bfs01(int source){
	dist.assign(n+1,1e18);
	visited.assign(n+1,0);
	deque<int>dq;
	dq.push_back(source);
	dist[source]=0;
	while(!dq.empty()){
		int node=dq.front();
		dq.pop_front();
		if(visited[node])continue;
		visited[node]=1;
		for(auto x:pos[arr[node]]){
			if(node==x)continue;
			if(dist[x]>dist[node]+a){
				dist[x]=dist[node]+a;
				if(a<b){
					dq.push_front(x);
				}else{
					dq.push_back(x);
				}
			}
		}
		for(int i=0;i<2;i++){
			int xx=node+dx[i];
			if(check(xx)&&dist[xx]>dist[node]+b){
				dist[xx]=dist[node]+b;
				if(a<b){
					dq.push_back(xx);
				}else{
					dq.push_front(xx);
				}
			}
		}
	}
}
void solve(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		pos[arr[i]].push_back(i);
	}
	int source;cin>>source;
	bfs01(source);
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" ";
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