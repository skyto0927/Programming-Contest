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
    int n,X; cin >> n >> X;
    vector<int> A(n);
    REP(i,n) cin >> A[i];
    int ans = 0;
    REP(i,n){
        if(X & 1<<i){
            ans += A[i];
        }
    }
    cout << ans << endl;
    return 0;
}