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
    int N,M; cin >> N >> M;
    vector<ll> L(M,0);
    vector<ll> R(M,0);
    REP(i,N){
        ll l,r,s; cin >> l >> r >> s;
        l--;
        r--;
        L[l] += s;
        R[r] += s;
    }

    if(M==1){
        cout << 0 << endl;
        return 0;
    }
    REP(i,M-1){
        R[i+1] += R[i];
        L[M-2-i] += L[M-1-i];
    }

    ll ans = max(L[1], R[M-2]);

    FOR(i,1,M-1){
        ans = max(ans, R[i-1] + L[i+1]);
    }
    cout << ans << endl;

    return 0;
}