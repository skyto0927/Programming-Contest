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
    vector<string> S_origin(N);
    REP(i,N){
        cin >> S_origin[i];
    }

    vector<string> S(S_origin);
    REP(i,N){
        REP(j,M){
            if(S[i][j]=='o'){
                S[i][j] = '.';
            }
        }
    }
    ll ans = 0;

    mf_graph<int> g(N*M+2);
    int s = N*M;
    int t = N*M+1;
    REP(i,N-1){
        REP(j,M-1){
            if(S[i][j]=='#') continue;

            if(S[i][j+1]=='.'){
                g.add_edge(i*M+j, i*M+j+1, 1);
            }
            if(S[i+1][j]=='.'){
                g.add_edge(i*M+j, (i+1)*M+j, 1);
            }
        }
    }

    REPR(i,N-1){
        REPR(j,M-1){

        }
    }
    

    return 0;
}