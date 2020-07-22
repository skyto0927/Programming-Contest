#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<ll> dp(100,0);
    dp[0]=2;
    dp[1]=1;
    REP(i,N){
        dp[i+2] = dp[i+1] + dp[i];
    }
    cout << dp[N] << endl;
    return 0;
}