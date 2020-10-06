#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

using S = ll;
S op(S a, S b){
    return min(a,b);
}

S e(){
    return LINF;
}

using F = ll;

S mapping (F f, S x){
    return min(f,x);
}

F composition(F f, F g){
    return min(f,g);
}
F id(){
    return LINF;
}

int main() {
    ll N,Q; cin >> N >> Q;

    vector<ll> a(N, N-2);
    lazy_segtree<S,op,e,F,mapping,composition,id> X(a), Y(a);
    int x_min = N-1;
    int y_min = N-1;

    ll ans = 0;

    REP(i,Q){
        int t; cin >> t;
        if(t==1){
            int x; cin >> x;
            x--;
            ans += X.get(x);
            //cout << X.get(x) << endl;

            if(x < x_min){
                x_min = x;
                Y.apply(0,y_min,x-1);
            }
        }else{
            int y; cin >> y;
            y--;

            ans += Y.get(y);

            //cout << Y.get(y) << endl;

            if(y < y_min){
                y_min = y;
                X.apply(0,x_min,y-1);
            }
        }
    }

    cout << (N-2)*(N-2) - ans << endl;
    
    return 0;
}