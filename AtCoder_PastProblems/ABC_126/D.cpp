#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


struct edge
{
    int to, d;
};

vector<vector<edge>> G;
vector<int> seen;

void dfs(int pos, int from){
    for(auto next: G[pos]){
        if (next.to == from){
            continue;
        }
        if(seen[next.to] == -1){
            seen[next.to] = seen[pos] ^ next.d;
            dfs(next.to, pos);
        }
    }
}


int main() {
   int N;
   cin >> N;

   G.assign(N,vector<edge>());
    REP(i,N-1){
        int u,v,w;
        cin >> u >> v >> w;
        u--;
        v--;
        w%=2;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }

    seen.assign(N,-1); //0...W, 1...B

    seen[0] = 0;

    dfs(0,-1);

    REP(i,N){
        cout << seen[i] << endl;
    }
    return 0;
}
