#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

int LIS(vector<int>& dp, vector<int> A, int N){
    REP(i,N){
        *lower_bound(ALL(dp), A[i]) = A[i];
    }

    return lower_bound(ALL(dp), INF) - dp.begin();
}

int main() {
    int N; cin >> N;
    vector<int> C(N);
    REP(i,N) cin >> C[i];
    vector<int> dp(N,INF);
    int ans = LIS(dp, C, N);
    cout << N-ans << endl;
    return 0;
}