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
    int h1,w1,h2,w2; cin >> h1 >> w1 >> h2 >> w2;
    cout << ((h1==h2 || h1==w2 || h2==w1 || w1==w2)?"YES":"NO") << endl;
    return 0;
}