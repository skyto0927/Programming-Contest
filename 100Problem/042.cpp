#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N, M;
    cin >> N >> M;
    vector<int>C(M);
    vector<int>D(N);
    REP(i,N) cin >> D[i];
    REP(j,M) cin >> C[j];

    vector<vector<int>> dp(N+1, vector<int>(M+1, INF));
    dp[0][0] = 0;
    REP(i,N){
        REP(j,M){
            dp[i][j+1] = min(dp[i][j+1], dp[i][j]);//stay
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + D[i]*C[j]);//go
        }
    }

    int ans = INF;
    REP(j,M+1){
        ans = min(ans, dp[N][j]);
    }

    cout << ans << endl;

    return 0;
}
