#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
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
    int H,W; cin >> H >> W;
    vector<vector<int>> c(10,vector<int>(10,0));
    vector<vector<int>> A(H,vector<int>(W,0));

    REP(i,10){
        REP(j,10){
            cin >> c[i][j];
        }
    }

    warshall_floyd(c);
    int ans = 0;
    REP(i,H){
        REP(j,W){
            int a; cin >> a;
            if(a != -1){
                ans += c[a][1];
            }
        }
    }
    cout << ans << endl;
    return 0;
}