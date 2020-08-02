#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
template<typename T>

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


int main() {
    return 0;
}
///////////////////////////////////////////////////////

//一番簡単なやつ

//基本的に1-indexedで考えること
//必要なサイズは2^(k-1) < N <= 2^kとして2^kだけ欲しい
//2*Nとしてしまえば安心

template<class T> struct BIT{
    vector<T> bit;
    int M;

    BIT(int M_):
        M(M_+1), bit(M_+1,0) {}

    T sum(int a){//sum [1,i) 1_indexed!!!!
        int ret = 0;
        for(int i=a; i>0; i-= i & -i) ret += bit[i];
        return ret;
    }
    
    T sum(int a, int b){//sum [i,j)  1_indexed!!!!
        return sum(b-1) - sum(a-1);
    }

    void add(int a, T x){
        for(int i=a; i<M; i+= i & -i) bit[i] += x;
    }

    void print(){
        FOR(i,1,M){
            cout << sum(i,i+1) << " ";
        }
        cout << endl;
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
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