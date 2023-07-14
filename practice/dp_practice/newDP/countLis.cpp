#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
pair<int,int> dp[1001];
bool computed[1001];
int arr[1001];
pair<int,int>rec(int level){//{length,count}
    //base case
    if(level==0){
        return dp[0]={1,1};
    }
    //cache check
    if(computed[level]){
        return dp[level];
    }
    computed[level]=1;
    int length=0;
    int count=0;
    for(int j=0;j<level;j++){
        if(arr[j]<arr[level]){
            if(length<rec(j).first){
                length=rec(j).first;
                count=rec(j).second;
            }else if(length==rec(j).first){
                count+=rec(j).second;
            }
        }
    }
    count=(count>0?count:1);
    return dp[level]={length+1,count};
}
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        computed[i]=0;
    }
    int lis=0,count=0;
    for(int i=0;i<n;i++){
        auto p=rec(i);
        if(lis<p.first){
            lis=p.first;
            count=p.second;
        }else if(lis==p.first){
            count+=p.second;
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