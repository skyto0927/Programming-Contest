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
    int w,a,b; cin >> w >> a >> b;
    if(a+w <= b) cout << b-a-w << endl;
    else if(b+w <= a) cout << a-b-w << endl;
    else cout << 0 << endl;
    return 0;
}