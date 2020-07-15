#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int D, N;
    cin >> D >> N;
    vector<int> T(D);
    REP(i,D) cin >> T[i];
    vector<vector<int>> ABC(N, vector<int>(3));
    REP(i,N) cin >> ABC[i][0] >> ABC[i][1] >> ABC[i][2];

    vector<vector<int>> dp(N,vector<int>(D, -INF));


    REP(i,N){
        if(ABC[i][0]<=T[0] && T[0]<=ABC[i][1]){
            dp[i][0] = 0;
        }
    }

    

    FOR(i,1,D){
        REP(j,N){
            if(ABC[j][0]<=T[i] && T[i]<=ABC[j][1]){
                REP(k,N){
                    dp[j][i] = max(dp[j][i], dp[k][i-1] + abs(ABC[k][2] - ABC[j][2]));
                }
            }
        }
    }
    int ans = 0;
    REP(i,N){
        ans = max(ans, dp[i][D-1]);
    }
    cout << ans << endl;
    return 0;
}
