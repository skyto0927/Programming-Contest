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
    int K; cin >> K;
    int ans = 0;
    int a = 0;
    while(1){
        a = (a*10 + 7)%K;
        ans++;
        if(a==0){
            cout << ans << endl;
            return 0;
        }
        if(ans > K){
            cout << -1 << endl;
            return 0;
        }
    }
    return 0;
}