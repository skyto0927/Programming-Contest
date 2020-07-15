#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


int main() {
    int N; cin >> N;
    vector<vector<int>> dp(2,vector<int>(120,0));
    dp[0][0] = 1;
    
    REP(j,100){            
        if(j+4<=N) dp[0][j+4] += dp[0][j];
        dp[1][j] += dp[0][j];
        if(j+7<=N) dp[1][j+7] += dp[1][j];
    }
    if(dp[1][N] > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}