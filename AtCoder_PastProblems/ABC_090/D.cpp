#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,K; cin >> N >> K;
    ll ans = 0;
    FOR(b,K+1,N+1){
        ans += (N+1) / b * (b-K);
        ans += max(0, (N+1)%b - K);
    }

    if(K==0) ans -= N;//コーナーケース、あまりが0のときはa=0を除外

    cout << ans << endl;
    return 0;
}