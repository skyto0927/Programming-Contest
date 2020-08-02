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
    vector<vector<int>> G(N,vector<int>(N,INF));
    REP(i,N){
        G[i][i] = 0;
    }
    REP(i,M){
        int a,b,c; cin >> a >> b >> c;
        a--;
        b--;
        G[a][b] = c;
        G[b][a] = c;
    }

    vector<vector<int>> G_origin(G);
    warshall_floyd(G);
    int ans = 0;
    REP(i,N){
        FOR(j,i+1,N){
            if(G[i][j]!=G_origin[i][j] && G_origin[i][j]!=INF) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}