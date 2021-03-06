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
    int N; cin >> N;
    string S; cin >> S;

    vector<vector<int>> dp(N+1, vector<int>(N+1,0));

    REP(i,N){
        REP(j,N){
            if(S[i] == S[j]){
                dp[i+1][j+1] = min(dp[i][j]+1, abs(i-j));
            }
        }
    }

    int ans = 0;
    REP(i,N+1){
        REP(j,N+1){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}