#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18




int main(){
    int N; cin >> N;
    vector<int> a(N); REP(i,N) cin >> a[i];

    vector<int> b(a);
    sort(ALL(b));
    b.erase(unique(ALL(b)), b.end());
    REP(i,N){
        cout << lower_bound(ALL(b), a[i]) - b.begin() << endl;
    }

    return 0;
}