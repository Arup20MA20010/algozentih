#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
int arr[1000][1000];
vector<int>visited;
void dfs(int node,int cmp){
    visited[node]=cmp;
    for(auto nbrs:g[node]){
        if(!visited[nbrs]){
            dfs(nbrs,cmp);
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    int count=0;
    char ch;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ch;
            if(ch=='.'){
                count++;
                arr[i][j]=count;
            }
        }
    }
    g.resize(count+1);
    visited.assign(count+1,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]!=0){
                if(i>0&&arr[i-1][j]!=0){
                    g[arr[i][j]].push_back(arr[i-1][j]);
                    g[arr[i-1][j]].push_back(arr[i][j]);
                }
                if(i<n-1&&arr[i+1][j]!=0){
                    g[arr[i][j]].push_back(arr[i+1][j]);
                    g[arr[i+1][j]].push_back(arr[i][j]);
                }
                if(j>0&&arr[i][j-1]!=0){
                    g[arr[i][j]].push_back(arr[i][j-1]);
                    g[arr[i][j-1]].push_back(arr[i][j]);
                }
                if(j<m-1&&arr[i][j+1]!=0){
                    g[arr[i][j]].push_back(arr[i][j+1]);
                    g[arr[i][j+1]].push_back(arr[i][j]);
                }
            }
        }
    }
    int cmp=0;
    for(int i=1;i<=count;i++){
        if(!visited[i]){
            cmp++;
            dfs(i,cmp);
        }
    }
    cout<<cmp<<nline;
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
}