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

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}

int main() {
    int N; cin >> N;
    vector<double> p(N);
    REP(i,N) cin >> p[i];
    vector<vector<double>> dp(N+1, vector<double>(N+1,0));//i枚中j枚が表
    dp[0][0] = 1.0;

    REP(i,N){
        REP(j,N){
            dp[i+1][j+1] += dp[i][j]*p[i];
            dp[i+1][j] += dp[i][j]*(1.0-p[i]);
        }
    }
    double ans = 0.0;
    FOR(i,N/2+1, N+1){
        ans += dp[N][i];
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}