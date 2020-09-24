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
    int N,M; cin >> N >> M;
    vector<string> S(N);
    REP(i,N) cin >> S[i];

    mf_graph<int> G(N*M + 2);
    int s = N*M;
    int t = N*M+1;
    REP(n,N){
        REP(m,M){
            if(S[n][m] == '#') continue;
            int v = n*M + m;
            if((n+m)%2 == 0){
                G.add_edge(s,v,1);
            }else{
                G.add_edge(v,t,1);
            }
        }
    }

    REP(n,N){
        REP(m,M){
            if((n+m)%2==1 || S[n][m]=='#') continue;

            int v_from = n*M + m;
            int v_to;
            if(n>0 && S[n-1][m]=='.'){
                v_to = (n-1)*M + m;
                G.add_edge(v_from, v_to, 1);
            }

            if(n<N-1 && S[n+1][m]=='.'){
                v_to = (n+1)*M + m;
                G.add_edge(v_from, v_to, 1);
            }

            if(m>0 && S[n][m-1]=='.'){
                v_to = n*M + m-1;
                G.add_edge(v_from, v_to, 1);
            }

            if(m<M-1 && S[n][m+1]=='.'){
                v_to = n*M + m+1;
                G.add_edge(v_from, v_to, 1);
            }
        }
    }

    cout << G.flow(s,t) << endl;

    auto edges = G.edges();
    for(auto e: edges){
        if(e.from==s || e.to ==t || e.flow==0) continue;
        
        int x0 = e.from/M;
        int y0 = e.from%M;
        int x1 = e.to/M;
        int y1 = e.to%M;

        if(y0+1 == y1){
            S[x0][y0] = '>';
            S[x1][y1] = '<';
        }else if(x0-1 == x1){
            S[x0][y0] = '^';
            S[x1][y1] = 'v';
        }else if(y0-1 == y1){
            S[x0][y0] = '<';
            S[x1][y1] = '>';
        }else if(x0+1 == x1){
            S[x0][y0] = 'v';
            S[x1][y1] = '^';
        }
        
    }

    REP(i,N) cout << S[i] << endl;

    return 0;
}