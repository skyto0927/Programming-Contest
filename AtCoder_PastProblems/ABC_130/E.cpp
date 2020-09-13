#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

const int MOD = 1e9+7;

int main() {
    ll N,M; cin >> N >> M;
    vector<ll> S(N), T(M);

    REP(i,N) cin >> S[i];
    REP(j,M) cin >> T[j];

    vector<vector<ll>> dp(N+1, vector<ll>(M+1,0));
    vector<vector<ll>> sum(N+1, vector<ll>(M+1,0));

    REP(i,N){
        REP(j,M){
            if(S[i] == T[j]){
                dp[i+1][j+1] = sum[i][j] + 1;
                dp[i+1][j+1] %= MOD;
            }
            sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] + dp[i+1][j+1];
            sum[i+1][j+1] %= MOD;

            sum[i+1][j+1] += MOD - sum[i][j];
            sum[i+1][j+1] %= MOD;
        }
    }

    ll ans = 1;
    REP(i,N+1){
        REP(j,M+1){
            ans += dp[i][j];
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}