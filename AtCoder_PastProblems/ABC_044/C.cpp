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
    int N,A; cin >> N >> A;
    vector<int> x(N);
    REP(i,N){
        int a; cin >> a;
        x[i] = a-A;
    }
    vector<vector<ll>> dp(N+1, vector<ll>(3000,0));
    int geta = 1500;

    dp[0][geta] = 1;
    REP(i,N){
        REP(j,3000){
            if(0<=j+x[i] && j+x[i]<3000){
                dp[i+1][j+x[i]] += dp[i][j];
            }
            dp[i+1][j] += dp[i][j];
        }
    }

    cout << dp[N][geta]-1 << endl;


    return 0;
}