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

    vector<vector<ll>> dp(S.size()+1, vector<ll>(13, 0));
    
    dp[0][0] = 1;
    REP(i,S.size()){
        REP(j,13){
            if(S[i] == '?'){
                REP(k,10){
                    dp[i+1][(j*10+k)%13] += dp[i][j];
                    dp[i+1][(j*10+k)%13] %= MOD;
                }

            }else{
                int num = S[i] - '0';
                dp[i+1][(j*10+num)%13] += dp[i][j];
                dp[i+1][(j*10+num)%13] %= MOD;
            }
        }
    }
    cout << dp[S.size()][5] << endl;

    return 0;
}