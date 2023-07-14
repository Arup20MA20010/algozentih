#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int freq[26];
void solve(){
    string s,ans;
    stack<char>t;
    cin>>s;
    for(int i=0;i<s.length();i++){
        freq[s[i]-'a']++;
    }
    int j=0;
    int n=s.length();
    for(int i=0;i<26;i++){
        while(!t.empty()&&t.top()<=i+'a'){
            ans.push_back(t.top());
            t.pop();
        }
        while(freq[i]){
            while(j<n&&s[j]!=i+'a'){
                freq[s[j]-'a']--;
                t.push(s[j]);
                j++;
            }
            if(j<n&&s[j]==i+'a'){
                freq[i]--;
                ans.push_back(s[j]);
                j++;
            }
        }
    }
    while(!t.empty()){
        ans.push_back(t.top());
        t.pop();
    }
    cout<<ans<<nline;
    for(int i=0;i<26;i++){
        freq[i]=0;
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