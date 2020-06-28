#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,M,Q; cin>> N >> M >> Q;
    vector<vector<int>> train(N+1, vector<int>(N+1,0));
    REP(i,M){
        int l,r; cin >> l >> r;
        train[l][r] ++;
    }

    REP(i,N+1){
        REP(j,N){
            train[i][j+1] += train[i][j];
        }
    }

    for(int i=N; i>=1; i--){
        REP(j,N+1){
            train[i-1][j] += train[i][j];
        }
    }

    REP(i,Q){
        int p,q; cin >> p >> q;
        cout << train[p][q] << endl;
    }

    return 0;
}