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
    int N,M,X,Y; cin >> N >> M >> X >> Y;
    REP(i,N){
        int x; cin >> x;
        X = max(X,x);
    }
    REP(i,M){
        int y; cin >> y;
        Y = min(Y,y);
    }

    if(X<Y) cout << "No War" << endl;
    else cout << "War" << endl;
    return 0;
}