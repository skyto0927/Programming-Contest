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
    vector<vector<int>> A(N,vector<int>(3));
    REP(i,N) cin >> A[i][0] >> A[i][1] >> A[i][2];
    vector<vector<int>> dp(N+1, vector<int>(3,0));
    REP(i,N){
        REP(j,3){
            if(dp[i][j]==-1) continue;
            chmax(dp[i+1][j], dp[i][(j+1)%3]+A[i][(j+1)%3]);
            chmax(dp[i+1][j], dp[i][(j+2)%3]+A[i][(j+2)%3]);
        }
    }
    cout << max({dp[N][0], dp[N][1], dp[N][2]}) << endl;
return 0;
}