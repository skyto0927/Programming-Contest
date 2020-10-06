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
    ll ans = LINF;
    for(ll i=1; i*i<=N; i++){
        if(N%i==0){
            ans = min(ans, N/i+i-2);
        }
    }
    cout << ans << endl;
    return 0;
}