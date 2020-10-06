
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

const int MOD = 1e9+7;

pair<ll,ll> dp[100000];
pair<ll,ll> dfs(vector<vector<int>> &G, int from, int pos){
    for(auto next: G[pos]){
        if(next==from) continue;
        auto cur = dfs(G,pos,next);
        dp[pos].first *= cur.first+cur.second;
        dp[pos].second *= cur.first;
        dp[pos].first %= MOD;
        dp[pos].second %= MOD;
    }
    return dp[pos];
}

int main() {
    int N; cin >> N;
    vector<vector<int>> G(N);
    REP(i,N-1){
        int x,y; cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    REP(i,N){
        dp[i] = {1,1};
    }
    pair<ll,ll> ans = dfs(G,-1,0);
    cout << (ans.first+ans.second)%MOD << endl;


    return 0;
}