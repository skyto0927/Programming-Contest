#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

const int MOD = 998244353;

int main() {
    int N,K; cin >> N >> K;
    vector<int> L(K),R(K);
    REP(i,K){
        cin >> L[i] >> R[i];
    }
    vector<ll> dp(N+1,0);
    dp[0] = 1;

    REP(i,N-1){
        if(i!=0) dp[i] += dp[i-1];
        dp[i] = (dp[i]+MOD)%MOD;
        REP(k,K){
            if(i+L[k] <= N-1){
                dp[i+L[k]] += dp[i];
                dp[i+L[k]] = (dp[i+L[k]]+MOD)%MOD;
            }
            if(i+R[k]+1 <= N-1){
                dp[i+R[k]+1] -= dp[i];
                dp[i+R[k]+1] = (dp[i+R[k]+1]+MOD)%MOD;
            }

        }
        // REP(i,N){
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
    }
    cout << (dp[N-1]+MOD)%MOD << endl;
    return 0;
}