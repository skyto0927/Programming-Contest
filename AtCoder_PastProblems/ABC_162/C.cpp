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
    int K; cin >> K;
    ll ans = 0;
    FOR(a,1,K+1){
        FOR(b,1,K+1){
            FOR(c,1,K+1){
                ans += __gcd(__gcd(a,b),c);
            }
        }
    }
    cout << ans << endl;
    return 0;
}