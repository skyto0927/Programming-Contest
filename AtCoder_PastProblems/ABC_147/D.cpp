#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

using mint = modint1000000007;

int main() {
    int N; cin >> N;
    vector<int> A(60,0);
    REP(i,N){
        ll a; cin >> a;
        REP(bit,60){
            A[bit] += a&1;
            a = a>>1;
        }
    }

    mint ans = 0;
    REP(i,60){
        ans += (N-A[i]) * A[i] * mint(2).pow(i);
    }
    cout << ans.val() << endl;
    return 0;
}