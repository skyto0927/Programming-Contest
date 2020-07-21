#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


vector<int> dx{1,0,-1,0};
vector<int> dy{0,-1,0,1};
int main() {
    int H,W; cin >> H >> W;
    vector<vector<char>> S(H+2, vector<char>(W+2, '.'));

    REP(i,H){
        string s; cin >> s;
        REP(j,W){
            S[i+1][j+1] = s[j];
        }
    }

    FOR(i,1,H+1){
        FOR(j,1,W+1){
            if(S[i][j] == '#'){
                bool ok = false;
                REP(n,4){
                    if(S[i+dy[n]][j+dx[n]] == '#') ok = true;
                }

                if(!ok){
                    cout << "No" << endl;
                    return 0;
                }
            }

        }
    }
    cout << "Yes" << endl;
    return 0;
}