#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,M; cin >> N >> M;
    vector<int> X(M); REP(i,M) cin >> X[i];
    sort(ALL(X));
    vector<int> dist(M-1); REP(i,M-1) dist[i] = X[i+1] - X[i];
    sort(ALL(dist));
    int ans = 0;
    REP(i, M-N){
        ans += dist[i];
    }
    cout << ans << endl;
    return 0;
}