#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}

const int MOD = 1e9+7;
int main() {
    int H,W; cin >> H >> W;
    vector<string> G(H);
    REP(i,H){
        cin >> G[i];
    }

    vector<vector<ll>> dp(H,vector<ll>(W,0));
    dp[0][0] = 1;
    REP(i,H){
        REP(j,W){
            if(G[i][j]=='#') continue;

            if(j+1<W && G[i][j+1]=='.'){
                dp[i][j+1] += dp[i][j];
                dp[i][j+1] %= MOD;
            }
            if(i+1<H && G[i+1][j]=='.'){
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= MOD;
            }
        }
    }
    cout << dp[H-1][W-1] << endl;
    return 0;
}