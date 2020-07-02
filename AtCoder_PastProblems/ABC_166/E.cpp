#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    ll N;
    cin >> N;

    map<ll,ll> A;
    map<ll,ll> B;
    REP(i,N){
        ll a;
        cin >> a;
        A[i+a]++;
        B[i-a]++;
    }
    ll ans = 0;
    for(auto x: A){
        ans += x.second * B[x.first];
    }

    cout << ans << endl;

    return 0;
}