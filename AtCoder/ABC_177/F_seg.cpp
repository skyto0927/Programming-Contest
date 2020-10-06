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

struct S{
    int a, itr;
};
S op(S a, S b){//始点と終点の距離（横移動）の最小を求める
    // if(a.a <= b.a){
    //     return a;
    // }else{
    //     return b;
    // }
    //return 
    return {min(a.a,b.a), min(a.itr,b.itr)};
}

S e(){//値が無限なのでx * e -> x
    return S{INF,INF};
}

struct F{//基準値（L-1の値）
    int a, itr;
};

S mapping(F f, S x){//更新
    if(f.a==-INF){
        return x;
    }else{
        return S{f.a + x.itr-f.itr, x.itr};
    }
}

F composition(F f, F g){// (f o g)(x) = f(g(x))
    return (f.a==-INF?g:f);
}

F id(){//この時だけ更新が行われない
    return {-INF,0};
}

int main() {
    int H,W; cin >> H >> W;
    lazy_segtree<S,op,e,F,mapping,composition,id> seg(W);
    REP(i,W){
        seg.set(i,{0,i});
    }

    REP(i,H){
        int l,r; cin >> l >> r;
        l--;
        if(l==0){
            seg.apply(l,r,{INF/2,0});
        }else{
            auto a = seg.get(l-1);

            seg.apply(l,r, {a.a, a.itr});
        }

        auto ans = seg.all_prod();
        if(ans.a >= INF/2){
            cout << -1 << endl;
        }else{
            cout << ans.a + i+1 << endl;
        }

        // REP(i,W){
        //     cout << seg.get(i).a << "," << seg.get(i).itr << " ";
        // }
        // cout << endl;

    }
    return 0;
}