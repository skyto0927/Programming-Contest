#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


template<class T> struct BIT{
    vector<T> bit;
    int M;

    BIT(int M_):
        M(M_+1), bit(M_+1,0) {}

    T sum(int a){//sum [1,i) 1_indexed!!!!
        int ret = 0;
        for(int i=a; i>0; i-= i & -i) ret = max(ret, bit[i]);
        return ret;
    }
    
    // T sum(int a, int b){//sum [i,j)  1_indexed!!!!
    //     return sum(b-1) - sum(a-1);
    // }

    void add(int a, T x){
        for(int i=a; i<M; i+= i & -i) bit[i] = max(bit[i],x);
    }

    void print(){
        FOR(i,1,M){
            cout << sum(i,i+1) << " ";
        }
        cout << endl;
    }
};


int main() {
    int N; cin >> N;
    vector<pair<int,int>> F(N);
    REP(i,N){
        int a,b; cin >> a >> b;
        F[i] = {a,-b};
    }

    sort(ALL(F));

    int ans = 0;
    BIT<int> bit(100200);
    REP(i,N){//
        int w = -F[i].second;
        int tmp = bit.sum(w-1) + 1;
        bit.add(w, tmp);
        ans = max(ans, tmp);

    }

    cout << ans << endl;


    return 0;
}