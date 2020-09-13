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
    int N,M; cin >> N >> M;
    vector<int> dp(N+1,0);
    REP(i,M){
        int a; cin >> a;
        dp[a] = -1;
    }

    dp[0] = 1;

    REP(i,N){
        if(dp[i] == -1) continue;

        if(dp[i+1] != -1){
            dp[i+1] += dp[i];
            dp[i+1] %= MOD;
        }

        if(i+2<=N && dp[i+2]!=-1){
            dp[i+2] += dp[i];
            dp[i+2] %= MOD;
        }
    }
    cout << dp[N] << endl;
    return 0;
}