#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,X; cin >> N >> X;
    vector<int> m(N);

    REP(i,N){
        cin >> m[i];
        X -= m[i];
    }
    sort(ALL(m));

    cout << N + X/m[0] << endl;
    return 0;
}