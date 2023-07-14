#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int x;
int test(int i){
    int k=1;
    return (x>>i)&k;
}
void setBit(int i){
    int k=1;
    x=x|(k<<i);
}
void clearBit(int i){
    int k=1;
    x=x&(~(k<<i));
}
void flipBit(int i){
    int k=1;
    x=x^(k<<i);
}
int all(){
    int k=1;
    if(x&(x+k)==0){
        return 1;
    }
    return 0;
}
int ifAny(){
    if(x!=0){
        return 1;
    }
    return 0;
}
int none(){
    if(x==0){
        return 1;
    }
    return 0;
}
int count(){
    return __builtin_popcountll(x);
}
int val(){
    return x;
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
    int q,i;
    int k=0;
    x=k<<60;
    while(t--){
        cin>>q;
        if(q==1){
            cin>>i;
            cout<<test(i)<<nline;
        }else if(q==2){
            cin>>i;
            setBit(i);
        }else if(q==3){
            cin>>i;
            clearBit(i);
        }else if(q==4){
            cin>>i;
            flipBit(i);
        }else if(q==5){
            cout<<all()<<nline;
        }else if(q==6){
            cout<<ifAny()<<nline;
        }else if(q==7){
            cout<<none()<<nline;
        }else if(q==8){
            cout<<count()<<nline;
        }else if(q==9){
            cout<<val()<<nline;
        }
    }
    return 0;
}