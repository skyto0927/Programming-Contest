#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;



//区間加算BIT

template<class T> struct BIT{
    int n;
    vector<T> bit[2];
    BIT(int n_){
        init(n_);
    }
    void init(int n_){ 
        n = n_+1;
        REP(p,2) bit[p].assign(n,0);
    }

    void add_sub(int p, int i, T x){
        for(int id=i; id<n; id += (id&-id)){
            bit[p][id] += x;
        }
    }
    void add(int l, int r, T x){// [l,r)に加算！
        add_sub(0,l,-x*(l-1));
        add_sub(0,r,x*(r-1));
        add_sub(1,l,x);
        add_sub(1,r,-x);
    }
    T sum_sub(int p, int i){
        T s(0);
        for(int id=i; id>0; id -= (id&-id)){
            s += bit[p][id];
        }
        return s;
    }
    T sum(int l, int r){
        return sum_sub(0,r-1) + sum_sub(1,r-1) * (r-1) 
            - sum_sub(0,l-1) - sum_sub(1,l-1) * (l-1);
    }
};

struct Kukan{
    int l,r,id;
    bool operator<(const Kukan &o) const{
        return r < o.r;
    }
};

int main() {
    int N,Q; cin >> N >> Q;
    vector<int> C(N);
    REP(i,N){
        int c; cin >> c;
        c--;
        C[i] = c;
    }
    vector<Kukan> kukan(Q);
    REP(i,Q){
        int l,r; cin >> l >> r;//[l,r)にする
        l--;
        kukan[i] = {l,r,i};
    }
    sort(ALL(kukan));

    BIT<int> bit(2*N);
    vector<int> pos(N,-1);//各ボールの最右を保存
    vector<int> ans(Q,0);

    int r = 0;
    for(auto k: kukan){
        while(r<k.r){
            bit.add(pos[C[r]]+2, r+2, 1);//その数に挟まれた区間に1加算(番兵が-1)
            pos[C[r]] = r;//最右を更新
            r++;//これを区間の右端まで行う
        }
        ans[k.id] = bit.sum(k.l+1, k.l+2);
    }

    REP(i,Q) cout << ans[i] << endl;
    return 0;
}