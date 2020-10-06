#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}

int dfs(vector<vector<int>> &G, vector<int> &dp, int pos){
    if(dp[pos] != -1) return dp[pos];
    dp[pos] = 0;
    for(auto next: G[pos]){
        chmax(dp[pos], dfs(G,dp,next)+1);

    }
    return dp[pos];
}

int main() {
    int N,M; cin >> N >> M;
    vector<vector<int>> G(N);
    REP(i,M){
        int x,y; cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
    }

    vector<int> dp(N,-1);
    int ans = 0;
    REP(i,N){
        chmax(ans, dfs(G, dp, i));
    }
    cout << ans << endl;
return 0;
}