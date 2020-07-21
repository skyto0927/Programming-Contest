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

    if(N>M) swap(N,M);

    if(N>1) cout << (N-2) * (M-2) << endl;
    else if(M!=1) cout << M-2 << endl;
    else cout << 1 << endl;

    return 0;
}