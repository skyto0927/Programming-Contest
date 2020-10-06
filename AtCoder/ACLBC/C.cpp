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
    dsu d(N);
    REP(i,M){
        int a,b; cin >> a >> b;
        a--;
        b--;
        d.merge(a,b);
    }
    cout << d.groups().size()-1 << endl;
    return 0;
}