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
    int N,Ma, Mb; cin >> N >> Ma >> Mb;

    vector<pair<int,int>> med(N);
    REP(i,N){
        int a,b,c; cin >> a >> b >> c;
        med[i] = {Mb*a-Ma*b, c};
    }
    int geta = 5000;
    int ans = INF;
    REP(k,N){
        vector<vector<int>> dp(N+1,vector<int>(10000,INF));
        dp[0][geta] = 0;
        REP(i,N){
            REP(j,10000){
                if(0<=j+med[i].first && j+med[i].first<10000){
                    dp[i+1][j+med[i].first] = min(dp[i+1][j+med[i].first], dp[i][j]+med[i].second);
                }
                if(k!=i) dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            }
        }
        if(dp[N][geta] != INF) ans = min(ans, dp[N][geta]);
    }
    
    if(ans != INF) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}