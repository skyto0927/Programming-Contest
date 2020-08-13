#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N; cin >> N;
    string S = to_string(N);
    ll dp[S.size()+1][10][2][12];
    REP(i,S.size()+1){
        REP(j,10){
            REP(k,2){
                REP(n,12){
                    dp[i][j][k][n] = 0;
                }
            }
        }
    }
    dp[0][0][0][0] = 1;

    REP(i,S.size()){
        int num = S[i] - '0';
        REP(j,10){
            REP(smaller,2){
                REP(x,(smaller?10:num+1)){
                    REP(n,10){
                        if(dp[i][j][smaller][n] != 0){
                            dp[i+1][x][smaller || x<num][x==1?n+1:n] += dp[i][j][smaller][n];
                        }
                    }
                }
            }
        }
    }

    ll ans = 0;
    
    REP(j,2){
        REP(i,10){
            REP(n,12){
                if(dp[S.size()][i][j][n] != -1){
                    ans += n*dp[S.size()][i][j][n];
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}