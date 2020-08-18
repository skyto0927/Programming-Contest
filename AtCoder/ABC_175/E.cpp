#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int R,C,K; cin >> R >> C >> K;
    vector<vector<int>> G(R,vector<int>(C,0));
    REP(i,K){
        int r,c,v; cin >> r >> c >> v;
        r--;
        c--;
        G[r][c] = v;
    }
    vector<vector<vector<ll>>> dp(R+1,vector<vector<ll>>(C, vector<ll>(4,0)));
    REP(i,R){
        REP(j,C){
            REP(k,4){
                if(j!=C-1) dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);//取らずに右
                dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][k]);//取らずに下
                if(k!=3){
                    if(j!=C-1) dp[i][j+1][k+1] = max(dp[i][j+1][k], dp[i][j][k]+G[i][j]);//取って右
                    dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][k]+G[i][j]);//取って下
                }
            }
            
        }
    }
    ll ans = 0;
    REP(i,4){
        ans = max(ans,dp[R][C-1][i]);
    }
    cout << ans << endl;

    return 0;
}