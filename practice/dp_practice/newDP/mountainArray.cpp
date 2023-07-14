#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<int>lis(vector<int>&arr){
    vector<int>temp;
    vector<int>ans;
    for(auto v:arr){
        if(temp.empty()||v>temp.back()){
            temp.push_back(v);
            ans.push_back(temp.size());
        }else{
            auto it=lower_bound(temp.begin(),temp.end(),v);
            *it=v;
            ans.push_back(it-temp.begin()+1);
        }
    }
    return ans;
}
vector<int>lds(vector<int>&arr){
    reverse(arr.begin(),arr.end());
    vector<int>ans=lis(arr);
    reverse(ans.begin(),ans.end());
    return ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    auto lisArr=lis(arr);
    auto ldsArr=lds(arr);
    int ans=0;
    for(int i=0;i<=n-1;i++){
        if(lisArr[i]>1&&ldsArr[i]>1){
            ans=max(ans,lisArr[i]+ldsArr[i]-1);
        }
    }
    cout<<(ans>0?n-ans:-1)<<nline;
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