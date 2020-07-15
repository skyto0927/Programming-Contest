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

//基本的に1-indexedで考えること
//必要なサイズは2^(k-1) < N <= 2^kとして2^kだけ欲しい
//2*Nとしてしまえば安心

template<class T> struct BIT{
    vector<T> bit;
    int M;

    BIT(int M_):
        M(M_+1), bit(M,0) {}

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