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
    int n,m; cin >> n >> m;
    double ns = 30*(n%12) + 0.5*m;//短針
    double ms = 6*m;
    cout << min(abs(ns-ms), 360-abs(ns-ms)) << endl;
    return 0;
}