#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;




int main() {
    int K; cin >> K;
    vector<double> R(1<<K);

    REP(i,1<<K) cin >> R[i];

    vector<vector<double>> dp(11,vector<double>(1<<10,0.0));
    vector<vector<double>> memo(1<<10,vector<double>(1<<10,0.0));

    REP(i,1<<K){
        REP(j,1<<K){
            memo[i][j] = 1.0 / (1.0+pow(10, (R[j]-R[i])/400.0));
        }
    }


    REP(i,1<<K){
        dp[0][i] = 1.0;
    }

    FOR(i,1,K+1){

        REP(j,(1<<K)-1){
            FOR(k,j+1,1<<K){
                if((j>>i)==(k>>i) && j&(1<<(i-1))^k&(1<<(i-1)) ){
                    dp[i][j] += dp[i-1][j]*dp[i-1][k]*memo[j][k];
                    dp[i][k] += dp[i-1][j]*dp[i-1][k]*memo[k][j];
                }
            }
        }
    }

    REP(i,1<<K){
        cout << fixed << setprecision(9) << dp[K][i] << endl;
    } 

    return 0;
}