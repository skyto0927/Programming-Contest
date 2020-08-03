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
    int N,x; cin >> N >> x;
    vector<int> a(N);
    REP(i,N) cin >> a[i];
    ll ans = 0;
    REP(i,N-1){
        if(a[i] + a[i+1] > x){
            if(a[i] <= x){
                ans += a[i+1] - x+a[i];
                a[i+1] = x - a[i];
            }else{
                ans += a[i+1];
                a[i+1] = 0;
                ans += a[i]-x;
                a[i] = x;
            }
        }
    }
    cout << ans << endl;
    return 0;
}