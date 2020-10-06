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

using S = int;
S op(S a, S b){
    return max(a,b);
}
S e(){
    return -1;
}

int main() {
    int N,K; cin >> N >> K;
    vector<int> A(N);
    REP(i,N){
        cin >> A[i];
    }

    vector<int> dp(N+1,0);
    segtree<S,op,e> seg(400000);
    REP(i,400000){
        seg.set(i,0);
    }

    REP(i,N){
        int next = seg.prod(max(0,A[i]-K), min(400000,A[i]+K+1)) + 1;
        int before = seg.get(A[i]);
        seg.set(A[i], max(before,next) );
    }

    
    cout << seg.all_prod() << endl;
    return 0;
}