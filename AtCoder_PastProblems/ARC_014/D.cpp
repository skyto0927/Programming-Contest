#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int all,N,M; cin >> all >> N >> M;
    vector<ll> L(N); REP(i,N) cin >> L[i];
    vector<ll> dist(N-1); REP(i,N-1) dist[i] = L[i+1] - L[i] - 1;
    sort(ALL(dist));


    vector<ll> sum(N);
    sum[0] = 0;
    FOR(i,1,N) sum[i] = dist[i-1] + sum[i-1];

    REP(i,M){
        ll x,y; cin >> x >> y;
        auto itr = lower_bound(ALL(dist), x+y);
        int it = itr - dist.begin();

        ll ans =  N + min(L[0]-1,x) + min(all-L[N-1], y) + sum[it] + (x+y)*(N-it-1);
        //cout << N << ", " << min(L[0]-1,x) << ", " << min(all-L[N-1], y) << ", " << sum[it] << ", " <<  (x+y)*(N-it-1) << endl;
        cout << ans << endl;
    }
    return 0;
}