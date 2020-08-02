#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9


int main() {
    return 0;
}
///////////////////////////////////////////////////////


//数値は適宜置き換えて
vector<vector<ll>> dp(60,vector<ll>(60,0));

void com_init(){
    REP(i,55){
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    FOR(n,1,55){
        FOR(k,1,n){
            dp[n][k] = dp[n-1][k-1] + dp[n-1][k];
        }
    }
}