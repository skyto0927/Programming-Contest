#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


const int MOD = 1000000007;
int main() {
    int N; cin >> N;
    ll dp[120][5][5][5];//0->A 1->C 2->G 3->T  4-> No

    REP(n,N){
        REP(i,5){
            REP(j,5){
                REP(k,5){
                    dp[n][i][j][k] = 0;
                }
            }
        }
    }

    dp[0][4][4][4] = 1;

    REP(n,N){
        REP(i,5){
            REP(j,5){
                REP(k,5){
                    REP(next,4){
                        if(j==0 && k==2 && next==1) continue;//AGC
                        if(j==0 && k==1 && next==2) continue;//ACG
                        if(j==2 && k==0 && next==1) continue;//GAC
                        if(i==0 && k==2 && next==1) continue;//A?GC
                        if(i==0 && j==2 && next==1) continue;//AG?C
                        dp[n+1][j][k][next] += dp[n][i][j][k];
                        dp[n+1][j][k][next] %= MOD;
                    }
                }
            }
        }
    }

    ll ans = 0;
    REP(i,4){
        REP(j,4){
            REP(k,4){
                ans += dp[N][i][j][k];
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}