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
    string O,E; cin >> O >> E;
    REP(i,E.size()){
        cout << O[i] << E[i];
    }
    if(O.size()-E.size() == 1) cout << O[O.size()-1];
    cout << endl;
    return 0;
}