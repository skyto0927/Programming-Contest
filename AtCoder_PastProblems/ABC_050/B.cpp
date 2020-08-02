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
    int n; cin >> n;
    vector<int> t(n);
    REP(i,n) cin >> t[i];
    int sum = 0;
    REP(i,n) sum += t[i];
    int m; cin >> m;
    REP(i,m){
        int p,x; cin >> p >> x;
        p--;
        cout << sum - t[p] + x << endl;
    }
    return 0;
}