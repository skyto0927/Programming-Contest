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
    int N,K; cin >> N >> K;
    vector<int> R(N);
    REP(i,N) cin >> R[i];
    sort(ALL(R));
    double ans = 0.0;
    FOR(i,N-K,N){
        ans = (ans+R[i])/2.0;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}