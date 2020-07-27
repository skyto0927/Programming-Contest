#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    ll N,K; cin >> N >> K;
    map<ll,ll> A;
    REP(i,N){
        ll a,b; cin >> a >> b;
        A[a] += b;
    }
    
    ll cnt = 0;
    for(auto a: A){
        cnt += a.second;
        if(cnt >= K){
            cout << a.first << endl;
            return 0;
        }
    }
    return 0;
}