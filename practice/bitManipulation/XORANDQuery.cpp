#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int arr[100100];
int prefixOne[100100][33];
int prefixZeros[100100][33];
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<31;j++){
            if((arr[i]>>j)&1){
                prefixOne[i][j]=1;
                prefixZeros[i][j]=0; 
            }else{
                prefixOne[i][j]=0;
                prefixZeros[i][j]=1;
            }
            if(i){
                prefixOne[i][j]+=prefixOne[i-1][j];
                prefixZeros[i][j]+=prefixZeros[i-1][j];
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        int x1=0,x2=0,x3=0;
        // calculating bit wise
        for(int j=0;j<31;j++){
            int noOfOnes=prefixOne[r][j]-(l>0?prefixOne[l-1][j]:0);
            int noOfZeros=prefixZeros[r][j]-(l>0?prefixZeros[l-1][j]:0);
            //calculating for x1
            if(noOfZeros>noOfOnes){
                x1+=(1<<j);
            }
            //calculating for x2
            if(noOfOnes!=(r-l+1)){
                x2+=(1<<j);
            }
            //calculating for x3
            if(noOfZeros!=(r-l+1)){
                x3+=(1<<j);
            }
        }
        cout<<x1+x2+x3<<nline;
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
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}