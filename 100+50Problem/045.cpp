#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    while(1){
        int N,M;
        cin >> N >> M;

        if (N==0 && M==0)break;

        vector<int>C(M);
        REP(i,M){
            cin >> C[i];
        }
        vector<int>x(N);
        REP(i,N){
            cin >> x[i];
        }

        vector<vector<ll>> dp(256, vector<ll>(N+1,INF));
        dp[128][0] = 0;

        REP(i,N){
            REP(j,256){
                REP(k,M){
                    if (j+C[k]>=255){
                        dp[255][i+1] = min(dp[255][i+1], dp[j][i] + (int)pow(x[i]-255, 2));
                    }else if (j+C[k]<=0){
                        dp[0][i+1] = min(dp[0][i+1], dp[j][i] + (int)pow(x[i], 2));
                    }else{
                        dp[j+C[k]][i+1] = min(dp[j+C[k]][i+1], dp[j][i] + (int)pow(x[i]-j-C[k], 2));
                    }
                    
                    
                }
            }
        }


        ll ans = INF;

        REP(i,256){
            ans = min(ans, dp[i][N]);
        }

        cout << ans << endl;
    }

    return 0;
}