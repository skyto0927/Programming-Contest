#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    ll a,b,c,d; cin >> a >> b >> c >> d;
    if((b<c) ||(d<a)){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}