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
    int K; cin >> K;
    int e,o;
    if(K%2==0){
        e = K/2;
        o = K/2;
    }else{
        e = K/2;
        o = K/2+1;
    }
    
    cout << e*o << endl;
    return 0;
}