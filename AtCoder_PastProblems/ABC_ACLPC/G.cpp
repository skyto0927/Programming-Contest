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
    scc_graph g(N);
    REP(i,M){
        int a,b; cin >> a >> b;
        g.add_edge(a,b);
    }

    auto ans = g.scc();

    cout << ans.size() << endl;
    for(auto es: ans){
        cout << es.size() << " ";
        for(auto e: es){
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}