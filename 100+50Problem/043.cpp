#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N;
    cin >> N;

    vector<vector<int>> color(3, vector<int>(N,0));

    REP(i,5){
        string S;
        cin >> S;
        REP(j,N){
            switch(S[j]){
                case 'R':
                    color[0][j]++;
                    break;

                case 'B':
                    color[1][j]++;
                    break;

                case 'W':
                    color[2][j]++;
                    break;
            }
        }
            
    }

    vector<vector<int>> dp(3, vector<int>(N+1,INF));

    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[2][0] = 0;

    REP(i,N){
        REP(j,3){
            REP(k,3){
                if (j!=k){
                    dp[k][i+1] = min(dp[k][i+1], dp[j][i]+5-color[k][i]);
                }
            }
        }
    }

    int ans = INF;
    REP(i,3){
        ans = min(ans, dp[i][N]);
    }
    cout << ans << endl;

    return 0;
}