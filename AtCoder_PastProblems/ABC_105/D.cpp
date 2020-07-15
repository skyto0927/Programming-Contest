#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


int main() {
    ll N,M; cin >> N >> M;
    vector<ll> A(N);
    ll sum = 0;
    map<ll,ll> B;
    REP(i,N){
        cin >> A[i];
        sum += A[i];
        B[sum%M] ++;
    }

    ll ans = B[0]; 
    for(auto n: B){
        ans += n.second * (n.second-1) / 2;
    }

    cout << ans << endl;
    
    return 0;
}