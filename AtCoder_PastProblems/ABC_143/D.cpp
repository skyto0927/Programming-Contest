#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<int> L(N);
    REP(i,N) cin >> L[i];
    sort(ALL(L));

    int ans = 0;

    REP(i,N-1){
        FOR(j,i+1,N){
            int itr = lower_bound(ALL(L), L[i]+L[j]) - L.begin();
            ans +=  itr - (j+1);
        }
    }
    cout << ans << endl;
    return 0;
}