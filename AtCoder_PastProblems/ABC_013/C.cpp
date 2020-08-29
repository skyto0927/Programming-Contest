#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

int main() {
    ll N,H; cin >> N >> H;
    ll A,B,C,D,E; cin >> A >> B >> C >> D >> E;

    ll ans = LINF;

    REP(i,N+1){
        ll j;
        if((N-i)*E - H - B*i < 0) j = 0;
        else j = max(0LL, 1LL + ((N-i)*E - H - B*i) / (D+E));
        if(i+j > N) continue;

        ans = min(ans, A*i + C*j);
    }
    cout << ans << endl;
    return 0;
}