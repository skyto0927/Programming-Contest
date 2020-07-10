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
    int N,K; cin >> N >> K;
    vector<ll> dp(N+2,0);
    dp[0] = 1;
    dp[1] = 0;

    vector<ll> sum(N+2,0);
    sum[1] = 1;

    FOR(n,1,N){
        dp[n+1] = sum[n] + dp[n];
        dp[n+1] %= MOD;
        if(n+1<K){
            sum[n+1] = sum[n] + dp[n];
            sum[n+1] %= MOD;
        
        }else{
            sum[n+1] = sum[n] + dp[n] - dp[n+1-K];
            sum[n+1] = (sum[n+1] + MOD) % MOD;
        }       
    }

    // REP(i,N+2){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << sum[N] << endl;
    return 0;
}