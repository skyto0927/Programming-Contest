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
    int a,b; cin >> a >> b;
    if(a<=5) cout << 0 << endl;
    else if(a<=12) cout << b/2 << endl;
    else cout << b << endl;
    return 0;
}