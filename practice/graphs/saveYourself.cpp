#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
vector<string>arr;
int n,m;
vector<vector<int>>dist1;
bool check(int i,int j){
	if(i<0||i>=n||j<0||j>=m||arr[i][j]=='#')return 0;
	return 1;
}
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
void multiSourceBfs(vector<ii>exits){
	dist1.assign(n,vector<int>(m,1e9));
	queue<ii>q;
	for(auto exit:exits){
		q.push(exit);
		dist1[exit.ff][exit.ss]=0;
	}
	while(!q.empty()){
		ii curr=q.front();
		q.pop();
		int x=curr.ff;
		int y=curr.ss;
		int currD=dist1[x][y];
		for(int dir=0;dir<4;dir++){
			int xx=x+dx[dir];int yy=y+dy[dir];
			if(check(xx,yy)&&dist1[xx][yy]>currD+1){
				dist1[xx][yy]=currD+1;
				q.push({xx,yy});
			}
		}
	}
}
vector<vector<int>>dist2;
void bfs(ii source){
	dist2.assign(n,vector<int>(m,1e9));
	queue<ii>q;
	q.push(source);
	dist2[source.ff][source.ss]=0;
	while(!q.empty()){
		ii curr=q.front();
		q.pop();
		int x=curr.ff;
		int y=curr.ss;
		int currD=dist2[x][y];
		for(int dir=0;dir<4;dir++){
			int xx=x+dx[dir];int yy=y+dy[dir];
			if(check(xx,yy)&&dist2[xx][yy]>currD+1){
				dist2[xx][yy]=currD+1;
				q.push({xx,yy});
			}
		}
	}
}
void solve(){
	cin>>n>>m;
	arr.resize(n);
	vector<ii>exits;
	ii source;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		for(int j=0;j<m;j++){
			if(arr[i][j]=='A'){
				source={i,j};
			}
			if(arr[i][j]=='M'){
				exits.push_back({i,j});
			}
		}
	}
	// for(int i=0;i<n;i++){
	// 	cout<<arr[i]<<nline;
	// }
	// for(auto exit:exits){
	// 	cout<<exit.ff<<" "<<exit.ss;
	// }
	bfs(source);
	// cout<<source.ff<<" "<<source.ss<<nline;
	multiSourceBfs(exits);
	int ans=1e9;
	//left border
	for(int i=0;i<n;i++){
		if(arr[i][0]!='#'&&arr[i][0]!='M'&&dist1[i][0]>dist2[i][0]){
			ans=min(ans,dist2[i][0]);
		}
	}
	//right border
	for(int i=0;i<n;i++){
		if(arr[i][m-1]!='#'&&arr[i][m-1]!='M'&&dist1[i][m-1]>dist2[i][m-1]){
			ans=min(ans,dist2[i][m-1]);
		}
	} 
	//top border
	for(int j=0;j<m;j++){
		if(arr[0][j]!='#'&&arr[0][j]!='M'&&dist1[0][j]>dist2[0][j]){
			ans=min(ans,dist2[0][j]);
		}
	}
	//bottom border
	for(int j=0;j<m;j++){
		if(arr[n-1][j]!='#'&&arr[n-1][j]!='M'&&dist1[n-1][j]>dist2[n-1][j]){
			ans=min(ans,dist2[n-1][j]);
		}
	}
	if(ans==1e9){
		cout<<"NO"<<nline;
		return;
	}
	cout<<"YES"<<nline;
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