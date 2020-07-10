#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    ll N,D; cin >> N >> D;

    vector<vector<vector<vector<double>>>> dp(2, vector<vector<vector<double>>>(65, vector<vector<double>>(65, vector<double>(65,0.0))));

    dp[0][0][0][0] = 1.0;

    int cur = 0;
    int next = 1;
    REP(i,N){
        REP(j,65) REP(k,65) REP(l,65) dp[next][j][k][l] = 0.0;
        REP(j,65){
            REP(k,65){
                REP(l,65){
                    if(dp[cur][j][k][l] == 0) continue;

                    dp[next][j][k][l] += dp[cur][j][k][l]/6;//1
                    dp[next][min(64,j+1)][k][l] += dp[cur][j][k][l]/6;//2
                    dp[next][j][min(64,k+1)][l] += dp[cur][j][k][l]/6;//3
                    dp[next][min(64,j+2)][k][l] += dp[cur][j][k][l]/6;//4
                    dp[next][j][k][min(64,l+1)] += dp[cur][j][k][l]/6;//5
                    dp[next][min(64,j+1)][min(64,k+1)][l] += dp[cur][j][k][l]/6;//6
                }
            }
        }
        swap(next,cur);
    }

    int count2 = 0;
    int count3 = 0;
    int count5 = 0;

    while(D%2 == 0){
        D/=2;
        count2++;
    }
    while(D%3 == 0){
        D/=3;
        count3++;
    }
    while(D%5 == 0){
        D/=5;
        count5++;
    }

    if(D>1){
        cout << fixed << setprecision(9) << 0.0 << endl;
    }else{
        double ans = 0.0;
        FOR(j,count2,65){
            FOR(k,count3,65){
                FOR(l,count5,65){
                    ans += dp[cur][j][k][l];
                }
            }
        }
        
        cout << fixed << setprecision(9) << ans << endl;
    }


    return 0;
}