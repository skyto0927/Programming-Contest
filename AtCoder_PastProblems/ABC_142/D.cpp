#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

vector<pair<ll,ll>> prime_fact(ll n){
    vector<pair<ll,ll>> a;
    if (n <= 1) return a;
    ll n_origin = n;
    for(ll i=2; i<=(ll)sqrt(n_origin); i++){
        if (n%i == 0){
            ll count = 0;
            while(n%i == 0){
                n/=i;
                count ++;
            }
            a.push_back(make_pair(i, count));
        }
    }
    if (n!=1){
        a.push_back(make_pair(n,1));
    }
    return a;
}

int main() {
    ll A,B; cin >> A >> B;
    ll G = __gcd(A,B);
    vector<pair<ll,ll>> SG = prime_fact(G);
    cout << SG.size() + 1 << endl;
    return 0;
}