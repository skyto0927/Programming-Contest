#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    ll N,M; cin >> N >> M;
    vector<pair<ll,ll>> AB(N);
    REP(i,N){
        ll a,b; cin >> a >> b;
        AB[i] = {a,b};
    }
    sort(ALL(AB));
    ll itr = 0;
    ll ans = 0;
    while(M>0){
        if(M>=AB[itr].second){
            M -= AB[itr].second;
            ans += AB[itr].first * AB[itr].second;
            itr++;
        }else{
            ans += AB[itr].first * M;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}