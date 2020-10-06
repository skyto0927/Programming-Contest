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


int main() {
    int N,M; cin >> N >> M;
    vector<pair<int, int>> edges(M);

    REP(i,M){
        int a,b; cin >> a >> b;
        int C = 0;
        REP(j,b){
            int c; cin >> c;
            c--;
            C += (1<<c);
        }
        edges[i] = {a,C};
    }
    vector<vector<int>> dp(M+1,vector<int>(1<<N,INF));
    dp[0][0] = 0;

    REP(i,M){
        REP(j,1<<N){
            dp[i+1][j|edges[i].second] = min(dp[i+1][j|edges[i].second], dp[i][j]+edges[i].first);
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        }
    }

    
    cout << (dp[M][(1<<N)-1]==INF?-1:dp[M][(1<<N)-1]) << endl;

    return 0;
}