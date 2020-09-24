#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

int main() {

    ll N; cin >> N;
    N *= 2;

    ll ans = LINF;

    vector<ll> div;
    for(ll i=1; i*i<=N; i++){
        if(N%i==0){
            div.push_back(i);
            if(i != N/i) div.push_back(N/i);
        }
    }
    sort(ALL(div));

    ll len = div.size();

    REP(i,div.size()){
        if(div[i] == div[len-1-i]) continue;
        ll tmp = crt({0ll,div[len-1-i]-1ll}, {div[i],div[len-1-i]}).first;
        if(tmp==0) continue;
        ans = min(ans, tmp);
    } 
    
    cout << ans << endl;
    return 0;
}