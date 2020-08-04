#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N,T; cin >> N >> T;
    vector<ll> a(N+1); 
    a[0] = LINF;
    REP(i,N) cin >> a[i+1];

    ll low = LINF;
    map<ll,int> b;
    REP(i,N){
        low = min(low, a[i]);
        b[low - a[i+1]] ++;
    }

    
    for(auto bb: b){
        cout << bb.second << endl;
        break;
    }

    return 0;
}