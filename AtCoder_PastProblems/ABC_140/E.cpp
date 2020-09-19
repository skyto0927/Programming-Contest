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
    int N; cin >> N;
    vector<ll> P(N);
    REP(i,N){
        ll p; cin >> p;
        P[p-1] = i+1;
    }
    multiset<ll> ms;
    ms.insert(0);
    ms.insert(0);
    ms.insert(N+1);
    ms.insert(N+1);

    ll ans = 0;
    REPR(i,N-1){
        auto itr = ms.lower_bound(P[i]);//現在の座標より大きい最小の座標
        ll pos_r,pos_r2, pos_l,pos_l2;
        pos_r = *itr;
        itr++;
        pos_r2 = *itr;

        itr--;
        itr--;
        pos_l = *itr;
        
        itr--;
        pos_l2 = *itr;
        ans += (i+1) * (pos_l - pos_l2) * (pos_r - P[i]);
        ans += (i+1) * (pos_r2 - pos_r) * (P[i] - pos_l);

        ms.insert(P[i]);
    }
    cout << ans << endl;

    return 0;
}