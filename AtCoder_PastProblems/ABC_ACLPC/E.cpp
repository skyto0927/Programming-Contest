#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    ll N,K; cin >> N >> K;
    mcf_graph<ll,ll> g(N*2 + 2);
    ll s = N*2;
    ll t = N*2 + 1;

    REP(i,N){
        g.add_edge(s,i,K,0);
        g.add_edge(N+i,t,K,0);
    }

    REP(i,N){
        REP(j,N){
            int a; cin >> a;
            g.add_edge(i,N+j,1,INF-a);
        }
    }
    g.add_edge(s,t,N*K,INF);

    auto ans = g.flow(s,t,N*K);

    ll f = INF*N*K - ans.second;

    cout << f << endl;

    vector<vector<char>> field(N,vector<char>(N, '.'));
    auto edges = g.edges();
    for(auto e: edges){
        if(e.from==s || e.to==t || e.flow==0) continue;
        field[e.from][e.to-N] = 'X';
    }
    REP(i,N){
        REP(j,N){
            cout << field[i][j];
        }
        cout << endl;
    }
    return 0;
}