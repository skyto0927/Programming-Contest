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
    int R; cin >> R;
    if(R<1200) cout << "ABC" << endl;
    else if(1200<=R && R<2800) cout << "ARC" << endl;
    else cout << "AGC" << endl;
    return 0;
}