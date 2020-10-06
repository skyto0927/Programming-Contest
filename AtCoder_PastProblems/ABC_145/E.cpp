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
    int N,T; cin >> N >> T;
    vector<pair<int,int>> A(N);
    REP(i,N) cin >> A[i].first >> A[i].second;
    vector<vector<int>> dp(N+1, vector<int>(T+1, 0));

    sort(ALL(A));
    REP(i,N){
        REP(t,T+1){
            if(t!=T){
                if(t+A[i].first >= T){
                    dp[i+1][T] = max(dp[i+1][T], dp[i][t]+A[i].second);
                }else{
                    dp[i+1][t+A[i].first] = max(dp[i+1][t+A[i].first], dp[i][t]+A[i].second);
                }
            }
            
            dp[i+1][t] = max(dp[i+1][t], dp[i][t]);
        }
    }

    int ans = 0;
    REP(i,T+1){
        ans = max(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}