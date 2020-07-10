#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,K; cin >> N >> K;
    vector<int> h(N); REP(i,N) cin >> h[i];
    sort(ALL(h));

    int ans = INF;
    REP(i,N-K+1){
        ans = min(ans, h[i+K-1] - h[i]);
    }

    cout << ans << endl;
    return 0;
}