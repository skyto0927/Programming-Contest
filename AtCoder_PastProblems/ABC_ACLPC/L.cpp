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

struct S{
    ll one, zero, inv;
};

S op(S a, S b){
    return {a.one+b.one, a.zero+b.zero, a.inv+b.inv+a.one*b.zero};
}

S e(){
    return {0,0,0};
}

using F = bool;

S mapping(F f, S s){
    if(f){
        return {s.zero, s.one, s.one*s.zero-s.inv};
    }else{
        return s;
    }
}

F composition(F f, F g){
    return (f^g);
}

F id(){
    return false;
}


int main() {
    int N,Q; cin >> N >> Q;
    lazy_segtree<S,op,e,F,mapping,composition,id> seg(N);
    REP(i,N){
        int a; cin >> a;
        seg.set(i,{a,1-a,0});
    }

    REP(i,Q){
        int t,l,r; cin >> t >> l >> r;
        l--;
        if(t==1){
            seg.apply(l,r,true);
        }else{
            cout << seg.prod(l,r).inv << endl;
        }
    }

    return 0;
}