#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

ll solve(ll N){
    string S = to_string(N);
    int d = S.size();


    vector<vector<vector<vector<ll>>>> dp(d+1, vector<vector<vector<ll>>>(2, vector<vector<ll>>(10,vector<ll>(2,-1))));
    //dp[d][lower][n][flag]
    dp[0][0][0][0] = 1;

    REP(i,d){
        int tmp = S[i]-'0';

        REP(j,2){//lower
            REP(k,10){

                REP(l,2){//条件を満たしているかどうか
                    if(dp[i][j][k][l]==-1) continue;

                    REP(m,(j==1?10:tmp+1)){
                        if(dp[i+1][j || (m<tmp)][m][l || (m==4 || m==9)] != -1){
                            dp[i+1][j || (m<tmp)][m][l || (m==4 || m==9)] += dp[i][j][k][l];
                        }else{
                            dp[i+1][j || (m<tmp)][m][l || (m==4 || m==9)] = dp[i][j][k][l];
                        }
                    }
                }
            }
        }
    }

    ll ans = 0;
    REP(i,10){
        REP(k,2){
            //cout << i << ", " << dp[d][k][i][1] << endl;
            if(dp[d][k][i][1] != -1) ans += dp[d][k][i][1];
        }
    }
    return ans;

}

int main() {
    ll A,B; cin >> A >> B;
    cout << solve(B) - solve(A-1) << endl;
    return 0;
}