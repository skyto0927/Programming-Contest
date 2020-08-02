#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

const int MOD = 1000000007;


int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<vector<ll>> dp(N+1, vector<ll>(13,0));
    dp[0][0] = 1;

    REP(i,N){
        if(S[i] != '?'){
            REP(j,13){
                int next = (j*10+(S[i]-'0')) % 13;
                dp[i+1][next] += dp[i][j];
                dp[i+1][next] %= MOD;
            }
        }else{
            REP(j,13){
                REP(k,10){
                    int next = (j*10+k) % 13;
                    dp[i+1][next] += dp[i][j];
                    dp[i+1][next] %= MOD;
                }
            }
        }
    }
    cout << dp[N][5] << endl;
    return 0;
}