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
    vector<int> h(N);
    REP(i,N){
        cin >> h[i];
    }

    vector<int> dp(N,INF);
    dp[0] = 0;
    
    REP(i,N){
        if(i+1<=N-1){
            dp[i+1] = min(dp[i+1], dp[i]+abs(h[i]-h[i+1]));
        }
        if(i+2<=N-1){
            dp[i+2] = min(dp[i+2], dp[i]+abs(h[i]-h[i+2]));
        }
    }
    cout << dp[N-1] << endl;
    return 0;
}