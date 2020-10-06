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


int main() {
    int H,W; cin >> H >> W;
    int A[80][80];

    REP(i,H){
        REP(j,W){
            cin >> A[i][j];
        }
    }
    REP(i,H){
        REP(j,W){
            int b; cin >> b;
            A[i][j] -= b;
            A[i][j] = abs(A[i][j]);
        }
    }

    int MAX_K = 10000;
    int dp[H][W][MAX_K];
    REP(i,H){
        REP(j,W){
            REP(k,MAX_K){
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][A[0][0]] = 1;

    REP(i,H){
        REP(j,W){
            REP(k,MAX_K){
                if(dp[i][j][k]==0) continue;
                //右方向
                if(j<W-1){
                    if(k+A[i][j+1]<MAX_K){
                        dp[i][j+1][k+A[i][j+1]] = 1;
                    }
                    if(abs(k-A[i][j+1]) < MAX_K){
                        dp[i][j+1][abs(k-A[i][j+1])] = 1;
                    }
                }

                //下方向
                if(i<H-1){
                    if(k+A[i+1][j]<MAX_K){
                        dp[i+1][j][k+A[i+1][j]] = 1;
                    }
                    if(abs(k-A[i+1][j]) < MAX_K){
                        dp[i+1][j][abs(k-A[i+1][j])] = 1;
                    }
                }
            }
        }
    }

    int ans = INF;
    REP(k,MAX_K){
        if(dp[H-1][W-1][k]){
            ans = min(ans,k);
        }
    }
    cout << ans << endl;
    return 0;
}