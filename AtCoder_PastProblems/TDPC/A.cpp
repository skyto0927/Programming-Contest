#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int S_MAX = 10100;
int N_MAX = 110;

int main() {
    int N; cin >> N;
    vector<int> p(N);
    REP(i,N){
        cin >> p[i];
    }
    vector<vector<int>> dp(N_MAX, vector<int>(S_MAX, 0));
    dp[0][0] = 1;
    REP(i,N){
        REP(j,S_MAX){
            dp[i+1][j] |= dp[i][j];//i番目を選ばない
            if(j+p[i]<=10000){
                
                dp[i+1][j+p[i]] |= dp[i][j];//i番目を選ぶ
            }
        }
    }

    // REP(i,N+1){
    //     REP(j,11){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = 0;
    REP(i,S_MAX){
        if(dp[N][i] == 1){
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}