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
    ll X,K,D; cin >> X >> K >> D;
    X = abs(X);

    ll N = X/D;
    if(N>=K) cout << abs(X - K*D) << endl;
    else{
        if((K-N)%2 == 0) cout << abs(X-N*D) << endl;
        else cout << abs(X-N*D-D) << endl;
    }
    return 0;
}