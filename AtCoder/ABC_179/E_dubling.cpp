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
    ll N,X,M; cin >> N >> X >> M;

    ll a = X;
    int K = 1;
    while((1<<K) <= N) K++;
    vector<vector<ll>> doubling(K+1, vector<ll>(M,-1));
    REP(i,M){
        doubling[0][i] = i*i%M;
    }

    REP(k,K){
        REP(i,M){
            doubling
        }
    }
    return 0;
}