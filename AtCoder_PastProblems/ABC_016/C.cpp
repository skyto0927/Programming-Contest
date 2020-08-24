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
    int n,m; cin >> n >> m;
    vector<vector<int>> G(n,vector<int>(n,INF));
    REP(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    REP(i,n) G[i][i] = 0;

    warshall_floyd(G);

    REP(i,n){
        int ans = 0;
        REP(j,n){
            if(G[i][j] == 2) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}