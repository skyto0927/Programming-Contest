#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

vector<int> d{-1,0,1};
int main() {
    int H,W; cin >> H >> W;
    vector<vector<char>> G(H+2, vector<char>(W+2,'#'));
    vector<vector<char>> ans(H+2, vector<char>(W+2,'.'));
    vector<vector<char>> check(H+2, vector<char>(W+2,'.'));

    REP(i,H){
        string s; cin >> s;
        REP(j,W){
            G[i+1][j+1] = s[j];
        }
    }
    FOR(i,1,H+1){
        FOR(j,1,W+1){
            bool ok = true;
            REP(x,3){
                REP(y,3){
                    if(G[i+d[x]][j+d[y]] == '.') ok = false;
                }
            }
            if(ok) ans[i][j] = '#';
        }
    }

    FOR(i,1,H+1){
        FOR(j,1,W+1){
            if(ans[i][j] == '.') continue;
            REP(x,3){
                REP(y,3){
                    check[i+d[x]][j+d[y]] = '#';
                }
            }
        }
    }
    bool ok = true;
    FOR(i,1,H+1){
        FOR(j,1,W+1){
            if(G[i][j] != check[i][j]) ok = false;
        }
    }

    if(!ok){
        cout << "impossible" << endl;
        return 0;
    }

    cout << "possible" << endl;
    FOR(i,1,H+1){
        FOR(j,1,W+1){
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}