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
    vector<ll> A(N);
    REP(i,N){
        ll a; cin >> a;
        A[i] = a-(i+1);
    }
    sort(ALL(A));
    ll b = A[N/2];
    ll ans = 0;

    REP(i,N){
        ans += abs(A[i] - b);
    }

    cout << ans << endl;
    return 0;
}