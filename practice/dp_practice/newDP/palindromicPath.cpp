#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n,m;
int dp[501][501][501];
char arr[501][501];
const int MOD=1e9+7;
int rec1(int r1,int c1,int r2){
    int c2=(m+n)-(r1+c1+r2)-2;
    if(r1>=n||c1>=m||r2<0||c2<0){
        return 0;
    }
    if((r1==r2)&&((c1==c2||c1==c2-1))||((r1==r2-1)&&(c1==c2))){
        return dp[r1][c1][r2]=1LL;
    }
    if(dp[r1][c1][r2]!=-1){
        return dp[r1][c1][r2];
    }
    if(arr[r1][c1]!=arr[r2][c2]){
        return dp[r1][c1][r2]=0;
    }
    int ans=((rec1(r1+1,c1,r2)+rec1(r1+1,c1,r2-1))%MOD+(rec1(r1,c1+1,r2)+rec1(r1,c1+1,r2-1))%MOD)%MOD;
    return dp[r1][c1][r2]=ans;
}
int rec2(int r1,int c1,int c2){
    int r2=(m+n)-(r1+c1+c2)-2;
    if(r1>=n||c1>=m||r2<0||c2<0){
        return 0;
    }
    if((r1==r2)&&((c1==c2||c1==c2-1))||((r1==r2-1)&&(c1==c2))){
        return dp[r1][c1][c2]=1LL;
    }
    if(dp[r1][c1][c2]!=-1){
        return dp[r1][c1][c2];
    }
    if(arr[r1][c1]!=arr[r2][c2]){
        return dp[r1][c1][c2]=0;
    }
    int ans=((rec2(r1+1,c1,c2)+rec2(r1+1,c1,c2-1))%MOD+(rec2(r1,c1+1,c2)+rec2(r1,c1+1,c2-1))%MOD)%MOD;
    return dp[r1][c1][c2]=ans;
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            for(int k=0;k<min(n,m);k++){
                dp[i][j][k]=-1;
            }
        }
    }
    if(n>m){
        cout<<rec2(0,0,m-1)<<nline;
    }else{
        cout<<rec1(0,0,n-1)<<nline;
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