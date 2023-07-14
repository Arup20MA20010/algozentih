#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define nline '\n'
void solve(){
	map<string,int>mp;
	int q;cin>>q;
	while(q--){
		string x;cin>>x;
		if(x=="add"){
			string name;
			int y;
			cin>>name>>y;
			mp[name]=y;
		}else if(x=="erase"){
			string name;cin>>name;
			if(mp.find(name)!=mp.end()){
				mp.erase(name);
			}
		}else{
			string name;cin>>name;
			if(mp.find(name)!=mp.end()){
				cout<<mp[name]<<nline;
			}else{
				cout<<0<<nline;
			}
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
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