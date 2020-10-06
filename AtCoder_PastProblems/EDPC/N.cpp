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

ll dp[500][500];
ll A[500];

ll sum[500];

ll rec(int l, int r){
    if(dp[l][r] != LINF) return dp[l][r];

    if(l==r) return dp[l][r] = 0;

    FOR(m,l,r){
        chmin(dp[l][r], rec(l,m) + rec(m+1,r));
    }
    return dp[l][r] = dp[l][r]+sum[r+1]-sum[l];
}

int main() {
    int N; cin >> N;
    REP(i,N) cin >> A[i];

    REP(i,N){
        sum[i] = 0;
    }
    REP(i,N){
        sum[i+1] = sum[i]+A[i];
    }

    REP(i,N){
        REP(j,N){
            dp[i][j] = LINF;
        }
    }

    cout << rec(0,N-1) << endl;

    return 0;
}