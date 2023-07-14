#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
#define ff first
#define ss second
using ii=pair<int,int>;

vector<string>arr;
int m,n;
bool isInside(int i,int j){
    if(i<0||i>=n||j<0||j>=m||arr[i][j]=='#')return 0;
    return 1;
}
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
/*
'S'...'W'
....'W'.
...'E'.w
*/
//this function finds the shortest path from start to end
vector<vector<int>>dist;
int bfs(ii st,ii et){
    dist.assign(n,vector<int>(m,1e9));
    dist[st.ff][st.ss]=0;
    queue<ii>q;
    q.push(st);
    while(!q.empty()){
        ii curr=q.front();
        q.pop();
        int x=curr.ff;
        int y=curr.ss;
        int currD=dist[x][y];
        for(int dir=0;dir<4;dir++){
            if(isInside(x+dx[dir],y+dy[dir])){
                if(dist[x+dx[dir]][y+dy[dir]]>currD+1){
                    dist[x+dx[dir]][y+dy[dir]]=currD+1;
                    q.push({x+dx[dir],y+dy[dir]});
                }
            }
        }
    }
    if(dist[et.ff][et.ss]==1e9){
        return -1;
    }
    return dist[et.ff][et.ss];
}
//now to find the no. of shortest path from start to end
vector<vector<ii>>distPair;//stores the pair {shortest distance, no of such paths}
vector<vector<ii>>parent;
ii bfsNO(ii st,ii et){
    distPair.assign(n,vector<ii>(m,{1e9,0}));
    parent.assign(n,vector<ii>(m,{-1,-1}));
    distPair[st.ff][st.ss]={0,1};
    queue<ii>q;
    q.push(st);
    while(!q.empty()){
        ii curr=q.front();
        q.pop();
        int x=curr.ff;
        int y=curr.ss;
        ii currD=distPair[x][y];
        //going through all the neighbours
        for(int dir=0;dir<4;dir++){
            if(isInside(x+dx[dir],y+dy[dir])){
                if(currD.ff+1<distPair[x+dx[dir]][y+dy[dir]].ff){
                    distPair[x+dx[dir]][y+dy[dir]]={currD.ff+1,currD.ss};
                    parent[x+dx[dir]][y+dy[dir]]=curr;
                    q.push({x+dx[dir],y+dy[dir]});
                }else if(currD.ff+1==distPair[x+dx[dir]][y+dy[dir]].ff){
                    distPair[x+dx[dir]][y+dy[dir]].ss+=currD.ss;
                }
            }
        }
    }
    return distPair[et.ff][et.ss];
}
vector<ii>path;
void generatePath(ii st,ii et){
    ii temp=et;
    while(temp!=st){
        path.push_back(temp);
        temp=parent[temp.ff][temp.ss];
    }
    path.push_back(temp);
    reverse(path.begin(),path.end());
}
void transformPath(ii st,ii et){
    ii temp=parent[et.ff][et.ss];
    while(temp!=st){
        arr[temp.ff][temp.ss]='P';
        temp=parent[temp.ff][temp.ss];
    }
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
            }
        }
    }
    cout<<bfs(st,et)<<nline;
    ii p=bfsNO(st,et);
    cout<<p.ff<<" "<<p.ss<<nline;
    generatePath(st,et);
    for(auto v:path){
        cout<<v.ff<<" "<<v.ss<<"->";
    }
    cout<<nline;
    transformPath(st,et);
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