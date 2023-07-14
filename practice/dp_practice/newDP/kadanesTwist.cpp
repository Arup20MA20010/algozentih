#include<bits/stdc++.h>
using namespace std;
#define nline '\n'
int kadane(vector<int>&arr){
    int sum=0;
    int maxSum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        maxSum=max(maxSum,sum);
        if(sum<0){
            sum=0;
        }
    }
    return maxSum;
}
int firstSum(vector<int>&arr){
    int maxSum=0;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        maxSum=max(maxSum,sum);
    }
    return maxSum;
}
int lastSum(vector<int>&arr){
    int maxSum=0;
    int sum=0;
    for(int i=arr.size()-1;i>=0;i--){
        sum+=arr[i];
        maxSum=max(maxSum,sum);
    }
    return maxSum;
}
int fullSum[100];
int beginSum[100];
int endSum[100];
int maxSum[100];
void solve(){
    int maxVal=-1000;
    int n;cin>>n;
    int m;cin>>m;
    for(int i=1;i<=n;i++){
        int l;cin>>l;
        vector<int>arr(l,0);
        int sum=0;
        for(int k=0;k<l;k++){
            cin>>arr[k];
            sum+=arr[k];
            maxVal=max(arr[k],maxVal);
        }
        fullSum[i]=sum;
        maxSum[i]=kadane(arr);
        beginSum[i]=lastSum(arr);
        endSum[i]=firstSum(arr);
    }
    int sum=0;
    int ans=0;
    int x;
    for(int i=0;i<m;i++){
        cin>>x;
        ans=max(ans,max(sum+endSum[x],sum+fullSum[x]));
        sum+=fullSum[x];
        if(sum<beginSum[x]){
            sum=beginSum[x];
        }
        ans=max(ans,max(sum,maxSum[i]));
    }
    if(ans==0){
        ans=maxVal;
    }
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
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}