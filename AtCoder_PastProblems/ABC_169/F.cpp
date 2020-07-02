#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

const int MOD = 998244353;

int main() {
    int N,S; cin >> N >> S;
    vector<ll> A(N);
    REP(i,N){
        cin >> A[i];
    }
    vector<vector<ll>> dp(N+1,vector<ll>(S+1,0));
    dp[0][0] = 1;
    REP(i,N){
        REP(j,S+1){
            dp[i+1][j] += 2*dp[i][j];
            dp[i+1][j] %= MOD;

            if(j+A[i] <= S){
                dp[i+1][j+A[i]] += dp[i][j];
                dp[i+1][j+A[i]] %= MOD;
            }
        }
    }
    
    cout << dp[N][S] << endl;

    return 0;
}