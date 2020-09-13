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
    int N; cin >> N;
    vector<int> W(N);
    REP(i,N) cin >> W[i];

    int s1 = 0;
    int s2 = 0;
    REP(i,N) s2 += W[i];

    int ans = INF;
    
    REP(i,N){
        ans = min(ans, abs(s1-s2));
        s1 += W[i];
        s2 -= W[i];
    }
    cout << ans << endl;
    return 0;
}