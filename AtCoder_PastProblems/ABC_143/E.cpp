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


struct Edge{
    ll to, cost;
};

const ll MAX_L = 1e15;

int main() {

    ll N,M,L; cin >> N >> M >> L;
    vector<vector<ll>> G(N, vector<ll>(N,MAX_L));//保存用
    REP(i,M){
        ll a,b,c; cin >> a >> b >> c;
        a--;
        b--;
        G[a][b] = c;
        G[b][a] = c;
    }
    REP(i,N){
        G[i][i] = 0;
    }

    REP(i,N){//ワーシャル
        REP(j,N){
            REP(k,N){
                G[j][k] = min(G[j][k], G[j][i]+G[i][k]);
            }
        }
    }

    vector<vector<ll>> G2(N, vector<ll>(N,MAX_L));//計算用
    REP(i,N){
        REP(j,N){
            if(G[i][j] <= L){
                G2[i][j] = 1;
                G2[j][i] = 1;
            }
        }
    }
    REP(i,N){
        G2[i][i] = 0;
    }

    REP(i,N){//ワーシャル
        REP(j,N){
            REP(k,N){
                G2[j][k] = min(G2[j][k], G2[j][i]+G2[i][k]);
            }
        }
    }


    int Q; cin >> Q;
    REP(i,Q){
        int s,t; cin >> s >> t;
        s--;
        t--;
        cout << (G2[s][t]>=MAX_L?-1:max(0ll,G2[s][t]-1)) << endl;
    }


    return 0;
}