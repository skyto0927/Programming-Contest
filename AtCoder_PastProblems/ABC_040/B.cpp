#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

ll sa(int n){
    if(n==0) return 0;
    REPR(i,sqrt(n)){
        if(n%i==0) return abs(n/i - i);
    }
    return 0;
}

int main() {
    ll n; cin >> n;
    ll ans = LINF;
    REP(i,n+1){
        ans = min(ans, (ll)(sa(i)+n-i));
    }
    cout << ans << endl;

    return 0;
}