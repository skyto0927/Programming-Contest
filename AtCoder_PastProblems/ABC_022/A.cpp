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
    int N,S,T; cin >> N >> S >> T;
    int W; cin >> W;
    int ans = 0;
    if(S<=W && W<= T) ans++;
    
    REP(i,N-1){
        int a; cin >> a;
        W += a;
        if(S<=W && W<= T) ans++;
    }
    cout << ans << endl;
    return 0;
}