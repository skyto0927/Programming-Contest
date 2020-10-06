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

struct goods{
    ll w,v;
};

int main() {
    int N,W; cin >> N >> W;
    vector<goods> A(N);
    REP(i,N) cin >> A[i].w >> A[i].v;

    vector<vector<ll>> dp(N+1, vector<ll>(W+1,0));

    REP(i,N){
        REP(j,W){
            if(j+A[i].w <= W){
                chmax(dp[i+1][j+A[i].w], dp[i][j] + A[i].v);
            }
            chmax(dp[i+1][j], dp[i][j]);

        }
    }

    ll ans = 0;
    REP(i,W+1){
        chmax(ans, dp[N][i]);
    }
    cout << ans << endl;
return 0;
}