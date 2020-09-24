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

using mint = modint998244353;

struct S{
    mint a;
    int size;
};

struct F{
    mint a,b;
};


S op(S l, S r){
    return S{l.a + r.a, l.size + r.size};
}

S e(){
    return S{0,0};
}

S mapping(F f, S s){
    return S{s.a*f.a + s.size*f.b, s.size};
}

F composition(F l, F r){
    return F{r.a*l.a, r.b*l.a + l.b};
}

F id(){
    return F{1,0};
}

int main() {
    int N,Q; cin >> N >> Q;

    lazy_segtree<S,op,e,F,mapping,composition,id> seg(N);


    REP(i,N){
        int a; cin >> a;
        seg.set(i,S{a,1});
    }

    REP(i,Q){
        int t; cin >> t;
        if(t==0){
            int l,r,b,c; cin >> l >> r >> b >> c;
            seg.apply(l,r,F{b,c});
        }else{
            int l,r; cin >> l >> r;
            cout << seg.prod(l,r).a.val() << endl;
        }
    }
    
    return 0;
}