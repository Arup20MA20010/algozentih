#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
#define ff first
#define ss second
using ii=pair<int,int>;
vector<string>arr;
int n,m;
bool ifInside(int i,int j){
	if(i<0||i>=n||j<0||j>=m||arr[i][j]=='W')return 0;
	return 1;
}
//U,L,D,R
char dir[]={'U','L','D','R'};
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
vector<ii>pos[4];
vector<vector<ii>>parent;
void Process(){
	for(int k=0;k<4;k++){
		for(auto p:pos[k]){
			int x=p.ff+dx[k];
			int y=p.ss+dy[k];
			while(ifInside(x,y)&&(arr[x][y]!=dir[k])){
				if(arr[x][y]=='.')arr[x][y]='B';
				x+=dx[k];y+=dy[k];
			}
		}
		for(auto p:pos[k]){
			arr[p.ff][p.ss]='B';
		}
	}
}
vector<vector<int>>dist;
int bfs(ii st,ii et){
	dist.assign(n,vector<int>(m,1e9));
	parent.assign(n,vector<ii>(m,{-1,-1}));
	dist[st.ff][st.ss]=0;
	queue<ii>q;
	q.push(st);
	while(!q.empty()){
		ii curr=q.front();
		q.pop();
		int currD=dist[curr.ff][curr.ss];
		int x=curr.ff;
		int y=curr.ss;
		for(int k=0;k<4;k++){
			if(ifInside(x+dx[k],y+dy[k])&&arr[x+dx[k]][y+dy[k]]!='B'){
				if(dist[x+dx[k]][y+dy[k]]>currD+1){
					dist[x+dx[k]][y+dy[k]]=currD+1;
					parent[x+dx[k]][y+dy[k]]=curr;
					q.push({x+dx[k],y+dy[k]});
				}
			}
		}
	}
	return dist[et.ff][et.ss];
}
void updatePath(ii st,ii et){
	ii temp=et;
	while(temp!=st){
		arr[temp.ff][temp.ss]='P';
		temp=parent[temp.ff][temp.ss];
	}
	arr[temp.ff][temp.ss]='P';
}
void solve(){
	cin>>n>>m;
	arr.resize(n);
	ii st,et;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		for(int j=0;j<m;j++){
			if(arr[i][j]=='S'){
				st={i,j};
			}else if(arr[i][j]=='E'){
				et={i,j};
			}else if(arr[i][j]=='U'){
				pos[0].push_back({i,j});
			}else if(arr[i][j]=='L'){
				pos[1].push_back({i,j});
			}else if(arr[i][j]=='D'){
				pos[2].push_back({i,j});
			}else if(arr[i][j]=='R'){
				pos[3].push_back({i,j});
			}
		}
	}
	Process();
	cout<<bfs(st,et)<<nline;
	updatePath(st,et);
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