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
    ll H,W,M; cin >> H >> W >> M;
    vector<pair<ll,ll>> P(M);
    vector<ll> H_cnt(H,0), W_cnt(W,0);
    REP(i,M){
        ll h,w; cin >> h >> w;
        h--;
        w--;
        P[i] = {h,w};
        H_cnt[h]++;
        W_cnt[w]++;
    }

    //M点について調べ、最大値とその組数を求める


    vector<ll> A(M);
    
    REP(i,M){
        A[i] = H_cnt[P[i].first] + W_cnt[P[i].second];
    }
    sort(ALL(A));
    ll a_max = A[M-1];
    ll as = A.end() - lower_bound(ALL(A), a_max);

    //cout << a_sum << " " << a_cnt << endl;

    //H*W点についても
    sort(ALL(H_cnt));
    sort(ALL(W_cnt));
    ll h_max = H_cnt[H-1];
    ll w_max = W_cnt[W-1];
    ll hs = H_cnt.end() - lower_bound(ALL(H_cnt), h_max);
    ll ws = W_cnt.end() - lower_bound(ALL(W_cnt), w_max);


    //cout << h_max+w_max << " " << hs << " " << ws << endl;
    if(h_max+w_max > a_max) cout << h_max + w_max << endl;
    else if(hs*ws - as == 0) cout << h_max + w_max - 1 << endl;
    else cout << h_max + w_max << endl;

    return 0;
}