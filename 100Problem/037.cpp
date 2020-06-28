#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int n, m;
vector<vector<int>> dp;
int main() {
    cin >> n >> m;
    vector<int> c(m);
    REP(i,m){
        cin >> c[i];
    }
    dp.assign(m+1, vector<int>(n+1,n));

    REP(i,m+1) dp[i][0] = 0;
    
    FOR(i,0,m){
        FOR(j,0,n+1){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);//選ばない

            if(j-c[i] >= 0){//選ぶ
                dp[i+1][j] = min(dp[i+1][j], dp[i][j-c[i]]+1);
                dp[i+1][j] = min(dp[i+1][j], dp[i+1][j-c[i]]+1);
            }
        }
    }

    cout << dp[m][n] << endl;

    return 0;
}
