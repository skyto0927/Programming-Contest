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

void dfs(vector<vector<int>> &G, vector<int> &dis, int pos){
    for(auto next: G[pos]){
        if(dis[next] != -1) continue;
        dis[next] = dis[pos] + 1;
        dfs(G,dis,next);
    }
    return;
}

int main() {
    int N,u,v; cin >> N >> u >> v;
    u--;
    v--;
    vector<vector<int>> G(N);
    REP(i,N-1){
        int a,b; cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dis_u(N,-1);
    dis_u[u] = 0;
    dfs(G, dis_u, u);

    vector<int> dis_v(N,-1);
    dis_v[v] = 0;
    dfs(G, dis_v, v);

    //REP(i,N) cout << dis_u[i] << " ";
    //cout << endl;

    //REP(i,N) cout << dis_v[i] << " ";
    //cout << endl;

    int max_u = 0;
    int max_v = 0;
    REP(i,N){
        if(dis_u[i] < dis_v[i]){//uが逃げる、vが追う　uが先に行ける場所で
            if(max_v < dis_v[i]){//vが最も時間のかかるところに逃げれば良い
                max_u = dis_u[i];
                max_v = dis_v[i];
            }
        }
    }

    cout << max_v-1 << endl;
    return 0;
}