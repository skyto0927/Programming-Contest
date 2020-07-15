#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


int main() {
    int N,K; cin >> N >> K;
    vector<ll> R(100100,INF);
    vector<ll> L(100100,INF);

    int r=1,l=1;

    L[0]=0;
    R[0]=0;

    REP(i,N){
        ll x; cin >> x;
        if(x>=0) R[r]=x, r++;
        else L[l]=-x, l++;
    }
    sort(ALL(L));

    ll ans = LINF;

    REP(i,K+1){
        ans = min(ans, 2*L[i]+R[K-i]);
        ans = min(ans, L[i]+2*R[K-i]);
    }

    cout << ans << endl;

    return 0;
}