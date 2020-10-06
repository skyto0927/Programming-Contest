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

int N;
int A[25][25];

ll dp[25][1ll<<21];
const int MOD = 1e9+7;

int main() {
    cin >> N;
    REP(i,N){
        REP(j,N){
            cin >> A[i][j];
        }
    }

    REP(i,N+1){
        REP(j,1ll<<N){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    REP(i,N){
        REP(j,1ll<<N){
            if(dp[i][j]==0) continue;
            REP(k,N){
                if(A[i][k]==1 && !(j&(1<<k))){
                    dp[i+1][j|(1<<k)] += dp[i][j];
                    dp[i+1][j|(1<<k)] %= MOD;
                }
            }
        }
    }

    cout << dp[N][(1ll<<N)-1] << endl;


    return 0;
}