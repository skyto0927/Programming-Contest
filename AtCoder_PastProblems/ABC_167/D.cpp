#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    ll N,K; cin >>N>>K;
    vector<ll> A(N+1);
    FOR(i,1,N+1){
        cin >> A[i];
    }

    ll start = 1;
    vector<ll> routes(N+1, -1);
    routes[1] = 0;
    
    ll roop_start, roop_end, roop_start_index;
    while(1){
        if(routes[A[start]] == -1){
            routes[A[start]] = routes[start] + 1;
            start = A[start];
        }else{
            roop_end = routes[start];
            roop_start = routes[A[start]];
            roop_start_index = A[start];
            break;
        }
    }


    ll ans = 1;
    if (K<=roop_end){
        REP(i,K){
            ans = A[ans];
        }

    }else{
        K -= roop_end+1;
        K %= (roop_end-roop_start+1);
    
        ans = roop_start_index;
        REP(i,K){
            ans = A[ans];
        }
    }

    cout << ans << endl;

    return 0;
}