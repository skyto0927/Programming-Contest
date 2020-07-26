#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

struct Coord{
    ll x,y,p;
};

struct DP{
    vector<ll> x_line;
    vector<ll> y_line;
    ll S;
};



int main() {
    ll N; cin >> N;
    cout << digits(N,5) << endl;
    return 0;
}