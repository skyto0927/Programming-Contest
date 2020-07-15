#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int n,m; cin >> n >> m;
    vector<int> city(n+1,0);
    vector<int> a(m);

    FOR(i,1,n){
        cin >> city[i];
        city[i] += city[i-1];
    }

    ll ans = 0;
    int current_city = 0;
    REP(i,m){
        cin >> a[i];
        ans += abs(city[current_city+a[i]] - city[current_city]);
        ans %= 100000;
        current_city += a[i];
    }

    cout << ans << endl;
    return 0;
}