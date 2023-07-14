#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int countBit[26];
    memset(countBit,0,sizeof(countBit));
    for(int j=0;j<26;j++){
        for(int i=0;i<n;i++){
            countBit[j]+=((arr[i]>>j)&1);
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        int num=0;
        for(int j=0;j<26;j++){
            if(countBit[j]){
                num+=(1<<j);
                countBit[j]--;
            }
        }
        sum+=num*num;
    }
    cout<<sum<<nline;
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