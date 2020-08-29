#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<int> ng(3);
    REP(i,3) cin >> ng[i];
    vector<vector<int>> dp(N+1, vector<int>(101,0));
    dp[0][0] = 1;

    REP(i,N){
        REP(j,100){
            FOR(k,1,4){
                if(i+k > N) continue;
                bool ok = true;
                REP(l,3){
                    if(ng[l] == i+k) ok = false;
                }
                if(ok) dp[i+k][j+1] += dp[i][j];
            }
        }
    }
    bool ans = false;
    REP(j,101){
        if(dp[N][j] > 0) ans = true;
    }

    cout << (ans?"YES":"NO") << endl;
    return 0;
}