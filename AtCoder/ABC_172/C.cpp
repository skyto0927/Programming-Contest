#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    int N,M,K; cin >> N >> M >> K;
    vector<ll> A(N+1, 0);
    vector<ll> B(M+1, 0);

    FOR(i,1,N+1){
        ll a;
        cin >> a;
        A[i] = a + A[i-1];
    }
    FOR(i,1,M+1){
        ll b;
        cin >> b;
        B[i] = b + B[i-1];
    }

    int ans = 0;

    REP(i,N+1){
        ll a_read_time = K-A[i];
        if (a_read_time < 0) continue;
        auto itr = upper_bound(ALL(B), a_read_time);
        int b_read_number = itr - B.begin() - 1;

        ans = max(ans, i+b_read_number);
    }

    cout << ans << endl;

    return 0;
}