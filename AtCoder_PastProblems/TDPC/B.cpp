#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int A,B; cin >> A >> B;
    vector<int> a(A);
    vector<int> b(B);
    REP(i,A) cin >> a[i];
    REP(i,B) cin >> b[i];

    vector<vector<vector<int>>> dp(A+1, vector<vector<int>>(B+1,vector<int>(2,0)));

    reverse(ALL(a));
    reverse(ALL(b));

    //0 が先手

    //初期化
    REP(i,B){
        dp[0][i+1][0] = dp[0][i][1] + b[i];
        dp[0][i+1][1] = dp[0][i][0];
    }

    REP(i,A){
        dp[i+1][0][0] = dp[i][0][1] + a[i];
        dp[i+1][0][1] = dp[i][0][0];
    }

    FOR(i,1,A+1){//もらう方で書く
        FOR(j,1,B+1){
            if(dp[i-1][j][1]+a[i-1] >= dp[i][j-1][1]+b[j-1]){
                dp[i][j][0] = dp[i-1][j][1]+a[i-1];
                dp[i][j][1] = dp[i-1][j][0];
            }else{
                dp[i][j][0] = dp[i][j-1][1]+b[j-1];
                dp[i][j][1] = dp[i][j-1][0];
            }
        }
    }

    // REP(i,A+1){
    //     REP(j,B+1){
    //         cout << "(" << dp[i][j][0] << "," << dp[i][j][1] << ") ";
    //     }
    //     cout << endl;
    // }

    cout << dp[A][B][0] << endl;



    return 0;
}