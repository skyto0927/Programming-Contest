#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}


int main() {
    int N,K; cin >> N >> K;
    vector<int> h(N);
    REP(i,N) cin >> h[i];

    vector<int> dp(N,INF);
    dp[0] = 0;

    REP(i,N){
        REP(k,K){
            if(i+k+1<=N-1){
                chmin(dp[i+k+1], dp[i]+abs(h[i] - h[i+k+1]));
            }
        }
    }
    cout << dp[N-1] << endl;

    return 0;
}