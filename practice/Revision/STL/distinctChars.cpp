#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	string s;cin>>s;
	int q;
	cin>>q;
	set<int>pos[26];
	for(int i=0;i<s.size();i++){
		pos[s[i]-'a'].insert(i+1);
	}
	while(q--){
		int x;cin>>x;
		if(x==1){
			int i;char c;
			cin>>i>>c;
            pos[s[i-1]-'a'].erase(i);
			pos[c-'a'].insert(i);
			s[i-1]=c;
		}else{
			int l,r;cin>>l>>r;
			int count=0;
			for(int i=0;i<26;i++){
				auto it=pos[i].lower_bound(l);
                if(it==pos[i].end()){
                    continue;
                }
				if(l<=*it&&*it<=r){
					count++;
				}
			}
			cout<<count<<nline;
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