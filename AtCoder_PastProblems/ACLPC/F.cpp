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
    vector<ll> a(N), b(M);
    REP(i,N) cin >> a[i];
    REP(j,M) cin >> b[j];

    vector<ll> c = convolution<998244353>(a,b);

    for(auto ans: c){
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}