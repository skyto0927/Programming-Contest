#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N;
    cin >> N;
    vector<vector<ll>> dp(21,vector<ll>(N,0));
    vector<int> equation(N);
    REP(i,N){
        cin >> equation[i];
    }

    dp[0][0] = 1;
    REP(j,N-1){
        REP(i,21){

            if (i+equation[j] <=20){
                dp[i+equation[j]][j+1] += dp[i][j];
            }

            if (i-equation[j] >=0 && j!=0){
                dp[i-equation[j]][j+1] += dp[i][j];
            }

            
        }
    }

    cout << dp[equation[N-1]][N-1] << endl;

    

    return 0;
}
