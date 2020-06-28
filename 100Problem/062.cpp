#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int H,W;
vector<vector<int>> A(200, vector<int>(200,INF));
vector<vector<int>> c(10, vector<int>(10,INF));

int main() {
    cin >> H >> W;
    REP(i,10){
        REP(j,10){
            cin >> c[i][j];
        }
    }

    REP(i,H){
        REP(j,W){
            cin >> A[i][j];
        }
    }

    REP(i,10){
        REP(j,10){
            REP(k,10){
                c[j][k] = min(c[j][k], c[j][i] + c[i][k]);
            }
        }
    }

    int ans = 0;

    REP(i,H){
        REP(j,W){
            if (A[i][j] == -1) continue;
            ans += c[A[i][j]][1];
        }
    }

    cout << ans << endl;
    
    return 0;
}