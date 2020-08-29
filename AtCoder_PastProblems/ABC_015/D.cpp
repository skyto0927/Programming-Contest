#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

typedef pair<int,int> P;

int main() {
    int W; cin >> W;
    int N,K; cin >> N >> K;
    vector<P> sc(N);
    REP(i,N){
        int a,b; cin >> a >> b;
        sc[i] = {a,b};
    }

    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(W+1, vector<int>(K+1,0)));

    REP(i,N){
        REP(j,W+1){
            REP(k,K+1){
                if(j+sc[i].first<=W && k<K && i>=k){
                    dp[i+1][j+sc[i].first][k+1] = max(dp[i+1][j+sc[i].first][k+1], dp[i][j][k]+sc[i].second);
                }
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
            }
        }
    }

    int ans = 0;
    REP(j,W+1){
        REP(k,K+1){
            ans = max(ans, dp[N][j][k]);
        }
    }
    cout << ans << endl;
    return 0;
}