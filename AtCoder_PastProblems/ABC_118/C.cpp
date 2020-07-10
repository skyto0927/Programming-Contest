#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<int> A(N); REP(i,N) cin >> A[i];

    int ans = INF;
    REP(i,N-1){
        ans = min(ans, __gcd(A[i],A[i+1]));
    }
    cout << ans << endl;
    return 0;
}