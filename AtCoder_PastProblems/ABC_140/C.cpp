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
    vector<int> B(N+1, INF);
    REP(i,N-1){
        cin >> B[i+1];
    }
    int ans = 0;
    REP(i,N){
        ans += min(B[i], B[i+1]);
    }
    cout << ans << endl;
    return 0;
}