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

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}

using S = ll;

S op(S a, S b){
    return max(a,b);
}

S e(){
    return 0;
}

int main() {
    int N; cin >> N;
    vector<int> h(N);
    REP(i,N) cin >> h[i];

    vector<ll> a(N);
    REP(i,N) cin >> a[i];

    segtree<S,op,e> seg(N+1);

    REP(i,N){
        seg.set(h[i], a[i] + seg.prod(0,h[i]));
    }

    cout << seg.all_prod() << endl;



    return 0;
}