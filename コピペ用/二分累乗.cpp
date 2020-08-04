#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9


int main() {
    return 0;
}
///////////////////////////////////////////////////////


ll modpow(const int &a,ll n){
    if(n==0)return 1;
    ll t=modpow(a,n/2);
    t=t*t;
    if(n&1)t=t*a;
    return t;
}