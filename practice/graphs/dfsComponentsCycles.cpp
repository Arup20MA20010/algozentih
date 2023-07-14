#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>col;
vector<int>parent;
vector<int>cycleChain;
vector<int>isPartOfCycle;
bool isCycle;
vector<int>preOrder;
void dfsCycle(int node,int par){
    parent[node]=par;
    col[node]=2;
    for(auto nbrs:g[node]){
        // if(nbrs==parent[node]){
        //     continue;
        // }//for undirected graphs
        if(col[nbrs]==1){
            dfsCycle(nbrs,node);
        }else if(col[nbrs]==2){
            //making the chain part of the cycle
            isPartOfCycle[parent[nbrs]]--;
            isPartOfCycle[node]++;
            //cycle detected
            if(isCycle==0){
                int temp=node;
                while(temp!=nbrs){
                    cycleChain.push_back(temp);
                    temp=parent[temp];
                }
                cycleChain.push_back(temp);
                reverse(cycleChain.begin(),cycleChain.end());
            }
            isCycle=1;

        }
    }
    preOrder.push_back(node);
    col[node]=3;
}
void solve(){
    int n,m;cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1,1);
    parent.assign(n+1,0);
   
    isCycle=0;
    isPartOfCycle.assign(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        //undirected graphs
        //g[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(col[i]==1){
            dfsCycle(i,0);
        }
    }
    for(auto node:preOrder){
        isPartOfCycle[parent[node]]+=isPartOfCycle[node];
    }
    int count=0;
    for(int i=1;i<n;i++){
        if(isPartOfCycle[i]>0){
            count++;
        }
    }
    cout<<count<<nline;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}