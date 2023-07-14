#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	priority_queue<int>pq;
	int q;cin>>q;
	while(q--){
		string s;
		cin>>s;
		if(s=="add"){
			int x;cin>>x;
			pq.push(x);
		}else if(s=="remove"){
			if(!pq.empty()){
				pq.pop();
			}
		}else{
			if(!pq.empty()){
				cout<<pq.top()<<nline;
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