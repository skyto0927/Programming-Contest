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
    int a,b,n; cin >> a >> b >> n;
    int g = a*b/__gcd(a,b);
    int ans = 0;
    while(ans<n) ans += g;
    cout << ans << endl;
    return 0;
}