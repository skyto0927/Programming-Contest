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
    int N,x; cin >> N >> x;
    vector<int> X(N+1);
    X[0] = x;
    vector<int> D(N);
    FOR(i,1,N+1){
        cin >> X[i];
    }
    sort(ALL(X));
    REP(i,N){
        D[i] = X[i+1] - X[i];
    }

    int ans = D[0];

    REP(i,N-1){
        ans = min(ans, __gcd(D[i], D[i+1]));
    }
    cout << ans << endl;
    return 0;
}