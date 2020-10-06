
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

ll dp[100100][2][100];

int main() {
    string K; cin >> K;
    int D; cin >> D;

    REP(i,K.size()+1){
        REP(j,2){
            REP(k,D){
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;

    REP(i,K.size()){//i桁目が
    int d = K[i]-'0';
        REP(smaller,2){//smaller?
            REP(j,(smaller?10:d+1)){//遷移先
                REP(k,D){//遷移前
                    dp[i+1][smaller || j<d][(j+k)%D] += dp[i][smaller][k];
                    dp[i+1][smaller || j<d][(j+k)%D] %= MOD;
                }
            }
        }
    }


    cout << (dp[K.size()][0][0]+dp[K.size()][1][0] - 1 + MOD)%MOD << endl;


    return 0;
}