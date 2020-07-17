#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int D,N; cin >> D >> N;
    if(N!=100) cout << N;
    else cout << 101;
    REP(i,D) cout << "00";
    cout << endl;
    return 0;
}