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
    int l,h; cin >> l >> h;
    int N; cin >> N;
    REP(i,N){
        int a; cin >> a;
        if(a<l)cout << l-a << endl;
        else if(a>h) cout << -1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}