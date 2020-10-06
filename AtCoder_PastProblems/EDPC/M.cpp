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

const int MOD = 1e9+7;

int main() {
    int N,K; cin >> N >> K;
    vector<int> A(N);
    REP(i,N) cin >> A[i];

    vector<vector<ll>> dp(N+1, vector<ll>(K+1,0));
    dp[0][0] = 1;

    vector<ll> sum(K+2,1);
    sum[0] = 0;

    REP(i,N){
        FOR(j,0,K+1){
            dp[i+1][j] = (sum[j+1] - sum[max(0,j-A[i])]+MOD)%MOD;
        }

        REP(j,K+1){
            sum[j+1] = sum[j] + dp[i+1][j];
            sum[j+1] %= MOD;
        }
    
    }
    // REP(i,N+1){
    //     REP(j,K+1) cout << dp[i][j] << " ";
    //         cout << endl;
    //     }
    cout << dp[N][K] << endl;
    return 0;
}