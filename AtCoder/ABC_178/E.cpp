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
    vector<pair<ll,ll>> P(N);
    ll max_X = -LINF;
    ll min_X = LINF;
    ll max_Y = -LINF;
    ll min_Y = LINF;
    REP(i,N){
        ll x,y; cin >> x >> y;
        //P[i] = {x-y, x+y};
        max_X = max(max_X, x-y);
        min_X = min(min_X, x-y);

        max_Y = max(max_Y, x+y);
        min_Y = min(min_Y, x+y);
    }

    cout << max(max_X-min_X, max_Y-min_Y) << endl; 

    return 0;
}