#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (int)1e9
#define LINF 1e18
typedef long long ll;


using mint = modint998244353;

vector<vector<mint>> ds(10,vector<mint>(300000,0));

struct S{
    mint d;
    int size;
};


S op(S a, S b){
    if(b.size==0){
        return a;
    }else if(a.size==0){
        return b;
    }else{
        return {a.d* ((mint)10).pow(b.size) + b.d, a.size+b.size};
    }
}

S e(){
    return {0,0};
}

using F = int;

S mapping(F f, S x){
    if(f==0){
        return x;
    }else{
        return {ds[f][x.size], x.size};
    }
}

F composition(F f, F g){
    return (f==0?g:f);
}

F id(){
    return 0;
}

int main() {
    int N,Q; cin >> N >> Q;

    FOR(i,1,10){
        REP(j,200500){
            ds[i][j+1] = ds[i][j]*10 + i;
        }
    }

    lazy_segtree<S,op,e,F,mapping,composition,id> seg(N);
    REP(i,N){
        seg.set(i,{1,1});
    }

    

    REP(i,Q){
        int l,r,d; cin >> l >> r >> d;
        l--;
        seg.apply(l,r,d);
        cout << seg.all_prod().d.val() << endl;
    }
    return 0;
}