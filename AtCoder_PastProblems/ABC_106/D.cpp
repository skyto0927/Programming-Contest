#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,M,Q; cin >> N >> M >> Q;
    vector<vector<int>> T(N, vector<int>(N,0));
    REP(i,M){
        int l,r; cin >> l >> r;
        l--; r--;
        T[l][r]++;
    }

    REP(i,N){
        REP(j,N-1){
            T[i][j+1] += T[i][j];
        }
    }

    for(int i=N-1; i>=1; i--){
        REP(j,N){
            T[i-1][j] += T[i][j];
        }
    }

    REP(i,Q){
        int p,q; cin >> p >> q;
        p--; q--;
        cout << T[p][q] << endl;
    }
    return 0;
}