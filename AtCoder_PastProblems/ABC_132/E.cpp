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
    int N,M; cin >> N >> M;
    vector<vector<int>> G(N,vector<int>());
    REP(i,M){
        int u,v; cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
    }

    int S,T; cin >> S >> T;
    S--;
    T--;

    vector<vector<int>> dist(N,vector<int>(3,-1));

    queue<pair<int,int>> q;
    q.push({S,0});

    dist[S][0] = 0;

    while(!q.empty()){
        auto p = q.front(); q.pop();
        int pos = p.first;
        int cnt = p.second;

        int n_cnt = (cnt+1)%3;

        for(auto next: G[pos]){
            if(dist[next][n_cnt] != -1) continue;

            dist[next][n_cnt] = dist[pos][cnt] + 1;
            q.push({next, n_cnt});
        }
    }

    if(dist[T][0] == -1) cout << -1 << endl;
    else cout << dist[T][0]/3 << endl;




    return 0;
}