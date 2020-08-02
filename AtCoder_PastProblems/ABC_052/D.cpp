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
    ll N,A,B; cin >> N >> A >> B;
    vector<ll> X(N);
    REP(i,N){
        cin >> X[i];
    }
    vector<ll> d(N-1);
    ll ans = 0;
    REP(i,N-1){
        ans += min((X[i+1] - X[i])*A, B);
    }
    cout << ans << endl;
    return 0;
}