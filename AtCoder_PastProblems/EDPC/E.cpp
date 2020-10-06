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

const ll MAX_V = 1e5+100;

int main() {
    int N,W; cin >> N >> W;
    vector<goods> A(N);
    REP(i,N) cin >> A[i].w >> A[i].v;

    vector<vector<ll>> dp(N+1, vector<ll>(MAX_V,LINF));

    dp[0][0] = 0;

    REP(i,N){
        REP(j,MAX_V){
            if(j+A[i].v < MAX_V && dp[i][j]+A[i].w <= W){
                chmin(dp[i+1][j+A[i].v], dp[i][j] + A[i].w);
            }
            chmin(dp[i+1][j], dp[i][j]);

        }
    }

    ll ans = 0;
    REP(i,MAX_V){
        if(dp[N][i]!=LINF) ans = i;
    }
    cout << ans << endl;
return 0;
}