#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int N, M;
int N_MAX = 300;
using P = pair<int,int>;
vector<vector<int>> G(N_MAX, vector<int>(N_MAX, INF));

int main() {
    cin >> N >> M;

    REP(i,M){
        int a,b,t;
        cin >> a >> b >> t;
        a--;
        b--;
        G[a][b] = t;
        G[b][a] = t;
    }

    REP(i,N){
        G[i][i] = 0;
    }

    REP(i,N){
        REP(j,N){
            REP(k,N){
                G[j][k] = min(G[j][k], G[j][i] + G[i][k]);
            }
        }
    }

    int ans = INF;
    REP(i,N){
        int d_max = 0;
        REP(j,N){
            d_max = max(d_max, G[i][j]);
        }
        ans = min(ans, d_max);
    }

    cout << ans << endl;
    
    return 0;
}