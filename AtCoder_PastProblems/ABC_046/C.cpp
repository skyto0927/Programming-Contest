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
    ll x=1, y=1;
    REP(i,N){
        ll t,a; cin >> t >> a;
        ll k1,k2;
        k1 = (x-1)/t + 1;
        k2 = (y-1)/a + 1;
        ll k = max(k1,k2);
        x = t*k;
        y = a*k;
        //cout << x << ", " << y << endl;
    }
    cout << x+y << endl;
    return 0;
}