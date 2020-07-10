#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e12
typedef long long ll;


int main() {
    ll A,B,Q; cin >> A >> B >> Q;
    vector<ll> S(A+2); FOR(i,1,A+1) cin >> S[i];
    vector<ll> T(B+2); FOR(i,1,B+1) cin >> T[i];
    vector<ll> x(Q); REP(i,Q) cin >> x[i];
    S[0] = -INF; S[A+1] = INF;
    T[0] = -INF; T[B+1] = INF;

    REP(i,Q){
        ll sl,sr,tl,tr;
        auto s_itr = lower_bound(ALL(S), x[i]);
        sr = *s_itr;
        sl = *(--s_itr);
        
        auto t_itr = lower_bound(ALL(T), x[i]);
        tr = *t_itr;
        tl = *(--t_itr);
        
        //cout << sl << ", " << sr << " " << tl << ", " << tr << " " << x[i] << endl;

        ll ans = 1e15;
        ans = min(ans, max(x[i]-sl, x[i]-tl));
        ans = min(ans, max(sr-x[i], tr-x[i]));

        ans = min(ans, 2*(x[i]-sl) + tr-x[i]);
        ans = min(ans, 2*(tr-x[i]) + x[i]-sl);

        ans = min(ans, 2*(x[i]-tl) + sr-x[i]);
        ans = min(ans, 2*(sr-x[i]) + x[i]-tl);

        cout << ans << endl;
    }

    


    return 0;
}