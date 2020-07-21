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

    vector<int> a(N);
    vector<int> b(N);
    REP(i,N) cin >> a[i];
    REP(i,N) cin >> b[i];

    ll ans = 0;

    REPR(digit,29){//逆順にすることでa,bの配列を再利用できる！！
        int beki = 1<<digit;
        REP(i,N){
            a[i] %= (beki<<1);
            b[i] %= (beki<<1);
        }
        sort(ALL(b));
        ll num = 0;
        REP(i,N){
            num += lower_bound(ALL(b), 2*beki - a[i])
                - lower_bound(ALL(b), beki - a[i]);

            num += lower_bound(ALL(b), 4*beki - a[i])
                - lower_bound(ALL(b), 3*beki - a[i]);
        }

        if(num%2==1) ans += beki;
    }

    cout << ans << endl;

    return 0;
}