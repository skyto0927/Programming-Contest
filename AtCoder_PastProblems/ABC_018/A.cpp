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
    vector<int> a(3); cin >> a[0] >> a[1] >> a[2];
    vector<int> X(a);
    sort(ALL(X));
    REP(i,3){
        int itr = lower_bound(ALL(X), a[i]) - X.begin();
        a[i] = 3-itr;
    }
    REP(i,3) cout << a[i] << endl;
    return 0;
}