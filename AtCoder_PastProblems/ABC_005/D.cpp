#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<vector<int>> D(N+1, vector<int>(N+1,0));
    REP(i,N){
        REP(j,N){
            cin >> D[i+1][j+1];
        }
    }

    REP(i,N){
        REP(j,N+1){
            D[i+1][j] += D[i][j];
        }
    }

    REP(i,N+1){
        REP(j,N){
            D[i][j+1] += D[i][j];
        }
    }

    vector<int> table(N*N+1,0);

    FOR(h,1,N+1){
        FOR(w,1,N+1){
            REP(i,N+1-h){
                REP(j,N+1-w){
                    table[h*w] = max(table[h*w], D[i][j] + D[i+h][j+w] - D[i][j+w] - D[i+h][j]);
                }
            }
        }
    }

    REP(i,N*N){
        table[i+1] = max(table[i+1], table[i]);
    }

    int Q; cin >> Q;
    vector<int> P(Q);
    REP(i,Q) cin >> P[i];
    REP(i,Q) cout << table[P[i]] << endl;
    return 0;
}