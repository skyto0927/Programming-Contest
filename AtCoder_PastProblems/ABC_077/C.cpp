#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<int> A(N), B(N), C(N);
    REP(i,N) cin >> A[i];
    REP(i,N) cin >> B[i];
    REP(i,N) cin >> C[i];

    sort(ALL(A));
    sort(ALL(B));
    sort(ALL(C));

    ll ans = 0;
    REP(i,N){
        ans += (lower_bound(ALL(A), B[i])-A.begin()) * (C.end()-upper_bound(ALL(C),B[i]));
    }

    cout << ans << endl;
    return 0;
}