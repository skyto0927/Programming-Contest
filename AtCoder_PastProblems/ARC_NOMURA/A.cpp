#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int h1,m1,h2,m2,k; cin >> h1 >> m1 >> h2 >> m2 >> k;
    int l = 60*h1 + m1;
    int r = 60*h2 + m2;
    cout <<  max(0,r-l-k) << endl;
    return 0;
}