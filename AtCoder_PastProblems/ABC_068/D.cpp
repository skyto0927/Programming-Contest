#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    ll K; cin >> K;
    ll a = K/50;
    ll b = K%50;
    cout << 50 << endl;
    REP(i,50-b) cout << 49-b+a << " ";
    REP(i,b) cout << 100-b+a << " ";
    cout << endl;
    return 0;
}