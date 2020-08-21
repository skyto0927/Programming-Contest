#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

template<class T> void warshall_floyd(vector<T>& G){
    int N = G.size();
    REP(k,N){
        REP(i,N){
            REP(j,N){
                G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
            }
        }
    }
}

int main() {
    int N,M; cin >> N >> M;
    vector<int> G0(N,INF);
    vector<vector<int>> G(N,vector<int>(N,INF));
    REP(i,M){
        int u,v,l; cin >> u >> v >> l;
        u--;
        v--;
        if(u==0){
            G0[v] = l;
        }else{
            G[u][v] = l;
            G[v][u] = l;
        }
    }

    REP(i,N) G[i][i] = 0;

    warshall_floyd(G);

    int ans = INF;
    REP(i,N-1){
        FOR(j,i+1,N){
            if(G[i][j]!=INF && G0[i]!=INF && G0[j]!=INF){
                ans = min(ans, G[i][j] + G0[i] + G0[j]);
            }
        }
    }

    cout << (ans==INF?-1:ans) << endl;
    
    return 0;
}