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
    ll N,M; cin >> N >> M;
    if(2*N > M) cout << M/2 << endl;
    else if(2*N<=M) cout << N + (M-2*N)/4 << endl;

    return 0;
}