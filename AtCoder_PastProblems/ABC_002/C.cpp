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
    int a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;
    int x,y,z,w;
    x = c-a;
    y = d-b;
    z = e-a;
    w = f-b;
    cout << fixed << setprecision(5) << abs(x*w-y*z)/2.0 << endl;
    return 0;
}