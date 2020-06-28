#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int q;
    cin >> q;
    REP(k,q){
        string X,Y;
        cin >> X;
        cin >> Y;
        int m,n;
        m = X.length();
        n = Y.length();

        vector<vector<int>> dp(m+1, vector<int>(n+1,0));

        REP(i,m){
            REP(j,n){
                if(X[i] == Y[j]){
                    dp[i+1][j+1] = max({dp[i+1][j+1], dp[i][j]+1});
                }
                dp[i+1][j+1] = max({dp[i+1][j+1], dp[i+1][j], dp[i][j+1]});
            }
        }
        cout << dp[m][n] << endl;
    }
    return 0;
}
