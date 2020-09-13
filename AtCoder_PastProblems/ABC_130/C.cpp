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
    ll W,H,x,y; cin >> W >> H >> x >> y;
    cout << fixed << setprecision(6) << W*H/2.0 << " ";
    cout << ((x*2==W && y*2==H)?1:0) << endl;
    return 0;
}