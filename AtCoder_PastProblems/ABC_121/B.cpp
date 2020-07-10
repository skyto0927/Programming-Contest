#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,M,C; cin >> N >> M >> C;
    vector<int> B(M);
    REP(i,M) cin >> B[i];
    vector<vector<int>> A(N, vector<int>(M));
    REP(i,N){
        REP(j,M){
            cin >> A[i][j];
        }
    }

    int ans = 0;
    REP(i,N){
        int sum = C;
        REP(j,M){
            sum += B[j] * A[i][j];
        }
        if (sum>0){
            ans ++;
        }
    }

    cout << ans << endl;
    return 0;
}