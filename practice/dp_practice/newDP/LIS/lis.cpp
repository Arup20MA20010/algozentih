#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
#define pvii pair<vector<int>,vector<int>>
pvii lis(vector<int>&arr){
    vector<int>pos;
    vector<int>temp;
    for(auto v:arr){
        if(temp.empty()||v>temp.back()){
            temp.push_back(v);
            pos.push_back(temp.size()-1);
        }else{
            auto it=lower_bound(temp.begin(),temp.end(),v);
            *it=v;
            pos.push_back(it-temp.begin());
        }
    }
    return {temp,pos};
}
pvii lds(vector<int>&arr){
    vector<int>temp=arr;
    reverse(temp.begin(),temp.end());
    auto pv=lis(temp);
    // reverse(pv.first.begin(),pv.second.end());
    // reverse(pv.second.begin(),pv.second.end());
    return pv;
}
void solve(){
    int n;cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    auto lisArr=lis(arr).second;
    auto ldsArr=lds(arr).second;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<nline;
    for(int i=0;i<n;i++){
        cout<<lisArr[i]<<" ";
    }
    cout<<nline;
    for(int i=0;i<n;i++){
        cout<<ldsArr[i]<<" ";
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