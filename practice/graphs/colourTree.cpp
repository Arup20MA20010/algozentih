#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int arr[100100];
void solve(){
    int n;cin>>n;
    int x,y;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        arr[x]++;
        arr[y]++;
    }
    int maxVal=0;
    for(int i=1;i<=n;i++){
        maxVal=max(maxVal,arr[i]);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<nline;
    cout<<maxVal+1<<nline;
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