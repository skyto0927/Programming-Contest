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
    vector<ll> dp(N,LINF);
    vector<ll> A(N);
    REP(i,N) cin >> A[i];
    dp[0] = 0;

    REP(i,N){
        if(i-1>=0) dp[i] = min(dp[i], dp[i-1] + abs(A[i-1] - A[i]));
        if(i-2>=0) dp[i] = min(dp[i], dp[i-2] + abs(A[i-2] - A[i]));
    }
    cout << dp[N-1] << endl;
    return 0;
}