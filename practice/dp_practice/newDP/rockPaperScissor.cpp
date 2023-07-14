/*
dp(index,moves,config) maximum no. of wins from index to N given config of index-1
dp(index,moves,config)=max(dp(index+1,moves-k,config')+condition(config'),dp(index+1,moves-k,config'')+condition(config''),dp(index+1,moves,config)+condition(config)
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;
int k;
string s;
string ans;
int dp[1100][1100][4];
int result(int state, char ch)
{
    if (ch == 'R')
    {
        return state == 1;
    }
    else if (ch == 'S')
    {
        return state == 2;
    }
    return state == 3;
}
int rec(int level, int moves, int config)
{
    if (moves < 0)
    {
        return -1e18;
    }
    if (level == n)
    {
        if(level){
            dp[level][moves][config]=result(config,s[level-1]);
        }
        return 0;
    }
    if (dp[level][moves][config] != -1)
    {
        return dp[level][moves][config];
    }
    int res = 0;
    int stateTaken=0;
    if (config == 0)
    {
        for (int state = 1; state <= 3; state++)
        {
            if (res < rec(level + 1, moves, state) + result(state, s[level]))
            {
                res = rec(level + 1, moves, state) + result(state, s[level]);
            }
            // res=max(res,rec(level+1,moves,state)+result(state,s[level]));
            
        }
        dp[level][moves][config]=res;
    }
    else
    {
        for (int state = 1; state <= 3; state++)
        {
            if (res < rec(level + 1, moves - (config != state), state) + result(state, s[level]))
            {
                res = rec(level + 1, moves - (config != state), state) + result(state, s[level]);
            }
            // res=max(res,rec(level+1,moves-(config!=state),state)+result(state,s[level]));
        }
    }
    dp[level][moves][config]=res;
    return dp[level][moves][config];
}
void solve()
{
    cin >> n >> k;
    cin >> s;
    // memset(dp, -1, sizeof(dp));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int state=0;state<4;state++){
                dp[i][j][state]=-1;
            }
        }
    }
    cout << rec(0, k, 0) << nline;
    // for(int i=n;i>=0;i--){
    //     for(int moves=k;moves>=0;moves--){
    //         cout<<dp[i][moves][0]<<" "<<" P "<<dp[i][moves][1]<<" R "<<dp[i][moves][2]<<" S "<<dp[i][moves][3]<<nline;
    //     }
    //     cout<<nline;
    //     cout<<nline;
    // }
    string ans;
    string symbol="PRS";
    int state=0;
    int maxVal=0;
    for(int i=1;i<4;i++){
        if(maxVal<result(i,s[0])+dp[1][k][i]){
            maxVal=result(i,s[0])+dp[1][k][i];
            state=i;
        }
    }
    ans.push_back(symbol[state-1]);
    int moves=k;
    for(int level=1;level<n;level++){
        if(moves==0){
            ans.push_back(symbol[state-1]);
        }else{
            int ch1=result(state,s[level])+dp[level+1][moves][state];
            int maxVal=0;
            int maxState=0;
            vector<int>equiState;
            for(int newState=1;newState<4;newState++){
                if(newState!=state){
                    if(maxVal<result(newState,s[level])+dp[level+1][moves-1][newState]){
                        maxVal=result(newState,s[level])+dp[level+1][moves-1][newState];
                        maxState=newState;
                    }
                    if(ch1==maxVal){
                        equiState.push_back(maxState);
                    }
                }
            }
            if(ch1<maxVal){
                state=maxState;
                moves--;
            }
            if(ch1==maxVal){
                sort(equiState.begin(),equiState.end());
                if(state>equiState[0]){
                    state=equiState[0];
                    moves--;
                }
            }
            ans.push_back(symbol[state-1]);
        }
    }
    cout<<ans<<nline;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}