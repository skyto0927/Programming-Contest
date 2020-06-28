#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {

    int n;
    cin >> n;
    vector<int> R(n);
    vector<int> C(n);
    REP(i,n) cin >> R[i] >> C[i];
    vector<vector<int>> dp(n,vector<int>(n,INF));

    REP(i,n) dp[i][i] = 0;

    FOR(w,1,n){
        FOR(l,0,n-w){
            int r = l+w; 
            FOR(m,l,r){
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m+1][r] + R[l]*C[m]*C[r]);
            }
        }

    }

    cout << dp[0][n-1] << endl;
    


    return 0;
}