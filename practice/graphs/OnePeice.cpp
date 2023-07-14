#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
int m,n;
vector<vector<int>>arr;
vector<vector<int>>dist;
bool check(int i,int j){
	if(i<0||j<0||i>=n||j>=m)return 0;
	return 1;
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int bfs01(ii start,ii end){
	dist.assign(n,vector<int>(m,1e18));
	dist[start.ff][start.ss]=0;
	deque<ii>dq;
	dq.push_back(start);
	while(!dq.empty()){
		ii curr=dq.front();
		dq.pop_front();
		int x=curr.ff;
		int y=curr.ss;
		int currD=dist[x][y];
		for(int dir=0;dir<4;dir++){
			int xx=x+dx[dir],yy=y+dy[dir];
			int weight=(arr[x][y]!=(dir+1));
			if(check(xx,yy)&&dist[xx][yy]>dist[x][y]+weight){
				dist[xx][yy]=dist[x][y]+weight;//relaxing condition
				if(weight){
					dq.push_back({xx,yy});
				}else{
					dq.push_front({xx,yy});
				}
			}
		}
	}
	return dist[end.ff][end.ss];
}
void solve(){
	cin>>n>>m;
	arr.assign(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	cout<<bfs01({0,0},{n-1,m-1})<<nline;

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