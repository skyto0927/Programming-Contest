#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    ll N; cin >> N;
    if(N%2==1){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    ll x = 5;
    while(x <= N/2){
        ans += (N/2)/x;
        x *= 5;
    }
    cout << ans << endl;
    return 0;
}