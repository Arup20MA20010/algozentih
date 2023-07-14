#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int H,W,N;
	cin>>H>>W>>N;
	multiset<int>heights;
	multiset<int>widths;
	set<int>Hcuts;
	set<int>Vcuts;
	Hcuts.insert(0);
	Hcuts.insert(H);
	Vcuts.insert(W);
	Vcuts.insert(0);
	heights.insert(H);
	widths.insert(W);
	for(int i=0;i<N;i++){
		char c;int x;
		cin>>c>>x;
		if(c=='H'){
			auto it1=lower_bound(Hcuts.begin(),Hcuts.end(),x);
			auto it2=it1;
			it2--;
			int h=*it1-*it2;
			int cut=x-*it2;
			heights.erase(heights.find(h));
			heights.insert(cut);
			heights.insert(h-cut);
			Hcuts.insert(x);
		}else{
			auto it1=lower_bound(Vcuts.begin(),Vcuts.end(),x);
			auto it2=it1;
			it2--;
			int h=*it1-*it2;
			int cut=x-*it2;
			widths.erase(widths.find(h));
			widths.insert(cut);
			widths.insert(h-cut);
			Vcuts.insert(x);
		}
		int h=*heights.rbegin();
		int w=*widths.rbegin();
		cout<<h*w<<nline;
	}
	heights.clear();
	widths.clear();
	Vcuts.clear();
	Hcuts.clear();
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