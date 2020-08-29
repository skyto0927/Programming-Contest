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
    vector<vector<int>> G(N, vector<int>(N,INF));
    REP(i,M){   
        int a,b,t; cin >> a >> b >> t;
        a--; b--;
        G[a][b] = t;
        G[b][a] = t;
    }
    REP(i,N) G[i][i] = 0;

    REP(i,N){
        REP(j,N){
            REP(k,N){
                G[j][k] = min(G[j][k], G[j][i] + G[i][k]);
            }
        }
    }

    int dist = INF;
    REP(i,N){
        int tmp = 0;
        REP(j,N){
            tmp = max(tmp, G[i][j]);
        }
        dist = min(dist, tmp);
    }

    cout << dist << endl;
    return 0;
}