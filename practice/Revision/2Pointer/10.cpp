#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;
int charIndex[26];
int leftIndex[100100];
int rightIndex[100100];
string s;
void solve(){
    cin>>n;
    for(int i=0;i<26;i++){
        charIndex[i]=-1;   
    }
    cin>>s;
    for(int i=0;i<n;i++){
        if(charIndex[s[i]-'a']==-1){
            leftIndex[i]=-1;
            charIndex[s[i]-'a']=i;
        }else{
            leftIndex[i]=charIndex[s[i]-'a'];
            charIndex[s[i]-'a']=i;
        }
    }
    for(int i=0;i<26;i++){
        charIndex[i]=n;
    }
    for(int i=n-1;i>=0;i--){
        if(charIndex[s[i]-'a']==n){
            rightIndex[i]=n;
            charIndex[s[i]-'a']=i;
        }else{
            rightIndex[i]=charIndex[s[i]-'a'];
            charIndex[s[i]-'a']=i;
        }
    }
    
    int score=0;
    for(int i=0;i<n;i++){
        score+=(i-leftIndex[i])*(rightIndex[i]-i);
    }
    cout<<score<<nline;
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