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
    int N,Q; cin >> N >> Q;
    dsu d(N);
    REP(i,Q){
        int t,u,v; cin >> t >> u >> v;
        if(t==0){
            d.merge(u,v);
        }else{
            cout << d.same(u,v) << endl;
        }
    }
    return 0;
}