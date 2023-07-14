#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
#define ff first
#define ss second
using ii=pair<int,int>;
vector<vector<int>>dist;
int m,n;
vector<string>arr;
bool check(int i,int j){
	if(i<0||i>=n||j<0||j>=m||arr[i][j]=='#')return 0;
	return 1;
}
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
vector<vector<ii>>parent;
void mulitSourceBfs(vector<ii>exits){
	queue<ii>q;
	dist.assign(n,vector<int>(m,1e9));
	parent.assign(n,vector<ii>(m,{-1,-1}));
	for(auto exit:exits){
		q.push(exit);
		dist[exit.ff][exit.ss]=0;
	}
	while(!q.empty()){
		ii curr=q.front();
		q.pop();
		int x=curr.ff;
		int y=curr.ss;
		int currD=dist[x][y];
		for(int dir=0;dir<4;dir++){
			if(check(x+dx[dir],y+dy[dir])&&dist[x+dx[dir]][y+dy[dir]]>currD+1){
				q.push({x+dx[dir],y+dy[dir]});
				dist[x+dx[dir]][y+dy[dir]]=currD+1;
				parent[x+dx[dir]][y+dy[dir]]=curr;
			}
		}
	}
}
void updatePath(vector<ii>sources){
	for(auto source:sources){
		ii temp=parent[source.ff][source.ss];
		while(arr[temp.ff][temp.ss]!='E'){
			arr[temp.ff][temp.ss]='P';
			temp=parent[temp.ff][temp.ss];
		}
	}
}
void solve(){
	cin>>n>>m;
	arr.resize(n);
	vector<ii>source;
	vector<ii>exits;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		for(int j=0;j<n;j++){
			if(arr[i][j]=='S'){
				source.push_back({i,j});
			}
			if(arr[i][j]=='E'){
				exits.push_back({i,j});
			}
		}
	}
	mulitSourceBfs(exits);
	for(auto p:source){
		cout<<dist[p.ff][p.ss]<<" ";
	}
	cout<<nline;
	updatePath(source);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<nline;
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
