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
    ll N,K; cin >> N >> K;
    ll l = K-1;
    ll r = N-K;
    ll cnt = l*r*6 + r*3 + l*3 + 1;
    cout << fixed << setprecision(20) << 1.0*cnt/pow(N,3) << endl;
    return 0;
}