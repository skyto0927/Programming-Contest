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
    ll N,K; cin >> N >> K;
    if(K%2 == 1){
        cout << (N/K)*(N/K)*(N/K) << endl;
    }else if(K%2 == 0){
        ll a = N/(K/2) - N/K;
        ll b = N/K;
        cout << a*a*a + b*b*b << endl;
    }
    

    return 0;
}