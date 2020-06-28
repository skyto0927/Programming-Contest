#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    int d0;
    cin >> d0;
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<int> d(n);
    d[0] = 0;
    FOR(i,1,n){
        cin >> d[i];
    }
    d.push_back(d0);

    sort(ALL(d));

    vector<int> k(m);

    ll sum = 0;
    REP(i,m) {
        cin >> k[i];
    }

    REP(i,m){
        auto itr = upper_bound(ALL(d), k[i]);
        int lower = *(itr-1);
        int upper = *itr;
        sum += min(abs(lower-k[i]), abs(upper-k[i]) );
    }

    cout << sum << endl;

    return 0;
}
