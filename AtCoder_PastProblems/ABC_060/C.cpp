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
    ll N,T; cin >> N >> T;
    vector<ll> t(N+1);
    REP(i,N){
        cin >> t[i];
    }
    t[N] = LINF;

    ll ans = 0;

    REP(i,N){
        ans += min(T,t[i+1]-t[i]);
    }

    cout << ans << endl;

    return 0;
}