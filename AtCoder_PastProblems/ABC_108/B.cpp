#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


int main() {
    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    int dx = x2-x1;
    int dy = y2-y1;
    cout << x2-dy << " " << y2+dx << " " << x1-dy << " " << y1+dx << endl;
    return 0;
}