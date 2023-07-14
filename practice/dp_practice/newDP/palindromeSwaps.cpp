#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
set<int>pos[26];
void solve(){
	int n;cin>>n;string s;
	cin>>s;
	for(int i=0;i<n;i++){
		pos[s[i]-'a'].insert(i);
	}
	int countEven=0;int countOdd=0;
	for(int i=0;i<26;i++){
		if(!pos[i].empty()){
			if(pos[i].size()&1){
				countOdd++;
			}else{
				countEven++;
			}
		}
	}
	if(n&1){
		if(countOdd!=1){
			cout<<-1<<nline;
			return;
		}
	}else{
		if(countOdd!=0){
			cout<<-1<<nline;
			return;
		}
	}
	int start=0,end=n-1;
	int count=0;
	while(start<=end){
		int lastIndex=*(pos[s[start]-'a'].rbegin());
		int firstIndex=*(pos[s[end]-'a'].begin());
		if(s[start]==s[end]){
			pos[s[start]-'a'].erase(start);
			pos[s[end]-'a'].erase(end);
			start++;
			end--;
			continue;
		}
		if(firstIndex-start<end-lastIndex){//if less swaps are required to swap last character to its correct position
			pos[s[start]-'a'].erase(start);
			pos[s[firstIndex]-'a'].erase(firstIndex);
			pos[s[firstIndex]-'a'].insert(start);
			pos[s[start]-'a'].insert(firstIndex);
			swap(s[firstIndex],s[start]);
			count+=(firstIndex-start);
		}else{//if less swaps are required to swap first character
			pos[s[end]-'a'].erase(end);
			pos[s[lastIndex]-'a'].erase(lastIndex);
			pos[s[lastIndex]-'a'].insert(end);
			pos[s[end]-'a'].insert(lastIndex);
			swap(s[lastIndex],s[end]);
			count+=(end-lastIndex);
		}
		pos[s[start]-'a'].erase(start);
		pos[s[end]-'a'].erase(end);
		start++;
		end--;
	}
	cout<<count<<nline;
	for(int i=0;i<26;i++){
		pos[i].clear();
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