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
    int k,s; cin >> k >> s;
    int ans = 0;
    REP(x,k+1){
        REP(y,k+1){
            if(x+y <= s && s-x-y<=k){
                ans ++;
            }
            
        }
    }
    cout << ans << endl;
    return 0;
}