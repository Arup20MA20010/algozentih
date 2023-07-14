#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	vector<int>frontVec;
	vector<int>backVec;
	int q;cin>>q;
	while(q--){
		string s;cin>>s;
		if(s=="insertback"){
			int x;cin>>x;
			backVec.push_back(x);
		}else if(s=="eraseback"){
			backVec.pop_back();
		}else if(s=="insertfront"){
			int x;cin>>x;
			frontVec.push_back(x);
		}else if(s=="erasefront"){
			frontVec.pop_back();
		}else if(s=="printfront"){
			if(frontVec.size()!=0){
				cout<<frontVec[frontVec.size()-1]<<nline;
			}else if(backVec.size()!=0){
				cout<<backVec[0]<<nline;
			}else{
				cout<<0<<nline;
			}
		}else if(s=="printback"){

		}else{

		}
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