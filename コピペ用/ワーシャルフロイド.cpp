#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
template<typename T>

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


int main() {
    return 0;
}
///////////////////////////////////////////////////////

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
