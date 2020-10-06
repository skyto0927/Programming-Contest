#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    ll A,B,K;  cin >> A >> B >> K;
    if(K<A) cout << A-K << " " << B << endl;
    else if(K-A<B) cout << 0 << " " << B-(K-A) << endl;
    else cout << "0 0" << endl;
    return 0;
}