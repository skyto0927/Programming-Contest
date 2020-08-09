#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N,K; cin >> N >> K;
    vector<ll> A(N);
    REP(i,N) cin >> A[i];
    vector<ll> sum(N+1,0);
    REP(i,N) sum[i+1] += sum[i]+ A[i];
    ll ans = 0;
    REP(i,N-K+1){
        ans +=  sum[K+i] - sum[i];
    }
    cout << ans << endl;
    return 0;
}