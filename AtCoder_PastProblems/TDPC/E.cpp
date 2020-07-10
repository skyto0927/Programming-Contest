#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

const int MOD = 1e9+7;

int main() {
    int D; cin >> D;
    string S; cin >> S;
    vector<vector<vector<ll>>> dp(S.size()+1, vector<vector<ll>>(D,vector<ll>(2,0)));


    dp[0][0][1] = 1;//0桁目を定めておく
    REP(i,S.size()){
        REP(j,D){
            REP(k,S[i]-'0'){
                dp[i+1][(j+k)%D][0] += dp[i][j][1];
                dp[i+1][(j+k)%D][0] %= MOD;
            }
            dp[i+1][(j+(S[i]-'0'))%D][1] += dp[i][j][1];
            dp[i+1][(j+(S[i]-'0'))%D][1] %= MOD;

            REP(k,10){
                dp[i+1][(j+k)%D][0] += dp[i][j][0];
                dp[i+1][(j+k)%D][0] %= MOD;
            }
        }
    }
    cout<< (dp[S.size()][0][0] + dp[S.size()][0][1]-1)%MOD << endl;

    return 0;
}