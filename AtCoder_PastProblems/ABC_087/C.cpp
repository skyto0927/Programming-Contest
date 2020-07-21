#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<vector<int>> A(2,vector<int>(N,0));
    REP(i,2){    
        REP(j,N){   
            cin >> A[i][j];
        }
    }
    vector<vector<int>> dp(2,vector<int>(N+1,0));
    dp[0][0] = 0;
    dp[1][0] = 0;

    REP(i,N){
        dp[0][i+1] = dp[0][i] + A[0][i];
    }
    FOR(i,1,N+1){
        dp[1][i] = max(dp[0][i],dp[1][i-1]) + A[1][i-1];
    }


    cout << dp[1][N] << endl;
    return 0;
}