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
    ll x; cin >> x;
    ll ans = 0;
    ans += (x/11)*2;
    x %= 11;

    if(0<x && x<=6) ans += 1;
    else  if(6<x) ans += 2;
    cout << ans << endl;

    return 0;
}