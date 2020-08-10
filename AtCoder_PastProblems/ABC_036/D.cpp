#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

const int MOD = 1e9+7;

vector<vector<int>> G(1e5);
pair<ll,ll> dfs(int from, int pos){
    ll b = 1;
    ll w = 1;
    for(auto next: G[pos]){
        if(next == from) continue;
        pair<ll,ll> bw = dfs(pos,next);
        b *= bw.second;
        w *= bw.first + bw.second;
        b %= MOD;
        w %= MOD;
    }
    return {b,w};
}


int main() {
    int N; cin >> N;
    REP(i,N-1){
        int a,b; cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    pair<ll,ll> ans = dfs(-1,0);
    cout << (ans.first + ans.second)%MOD << endl;


    return 0;
}