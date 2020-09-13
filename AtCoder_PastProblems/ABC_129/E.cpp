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
    string L; cin >> L;
    int s = L.size();
    vector<vector<ll>> dp(s+1, vector<ll>(2,0));
    dp[0][0] = 1;

    REP(i,s){
        if(L[i] == '1'){
            dp[i+1][0] += 2*dp[i][0];
            dp[i+1][1] += dp[i][0] + 3*dp[i][1];
        }else{
            dp[i+1][0] += dp[i][0];
            dp[i+1][1] += 3*dp[i][1];
        }
        dp[i+1][0] %= MOD;
        dp[i+1][1] %= MOD;
    }
    cout << (dp[s][0] + dp[s][1]) % MOD << endl;
    return 0;
}