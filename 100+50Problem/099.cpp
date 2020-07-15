#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    ll M; cin >> M;
    ll sum = 0;
    ll digits = 0;
    REP(i,M){
        ll c,d; cin >> c >> d;
        sum += c*d;
        digits += d;
    }
    cout << (digits-1) + (sum-1)/9 << endl;
    return 0;
}