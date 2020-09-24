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

int op(int a, int b){
    return max(a,b);
}

int e(){
    return -1;
}

int c;

bool f(int x){
    return (c>x?1:0);
}


int main() {
    int N,Q; cin >> N >> Q;
    segtree<int,op,e> seg(N);

    REP(i,N){
        int a; cin >> a;
        seg.set(i,a);
    }

    REP(i,Q){
        int t,a,b; cin >> t >> a >> b;

        if(t==1) seg.set(a-1,b);
        if(t==2) cout << seg.prod(a-1,b) << endl;
        if(t==3){
            c = b;
            cout << seg.max_right<f>(a-1) + 1 << endl;
        }
    }

    return 0;
}