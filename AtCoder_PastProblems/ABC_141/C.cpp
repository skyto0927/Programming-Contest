#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    ll N,K,Q; cin >> N >> K >> Q;
    vector<ll> A(N, K-Q);
    REP(i,Q){
        int a; cin >> a;
        a--;
        A[a] ++;
    }
    REP(i,N){
        cout << (A[i]>0?"Yes":"No") << endl;
    }

    return 0;
}