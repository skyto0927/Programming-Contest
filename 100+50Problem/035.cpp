#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int N, W;
vector<vector<int>> dp;
int main() {
    cin >> N >> W;
    vector<int> v(N);
    vector<int> w(N);
    REP(i,N){
        cin >> v[i] >> w[i];
    }
    dp.assign(N+1, vector<int>(W+1,0));
    FOR(i,0,N){
        FOR(j,0,W+1){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);

            if(j-w[i] >= 0){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-w[i]]+v[i]);
            }
        }
    }

    cout << dp[N][W] << endl;

    return 0;
}
