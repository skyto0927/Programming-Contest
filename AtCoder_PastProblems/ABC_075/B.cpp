#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

vector<int> dx{-1,0,1};
vector<int> dy{-1,0,1};

int main() {
    int H,W; cin >> H >> W;
    vector<vector<char>> G(H+2, vector<char>(W+2,'.'));
    REP(i,H){
        string S; cin >> S;
        REP(j,W){
            G[i+1][j+1] = S[j];
        }
    }
    FOR(i,1,H+1){
        FOR(j,1,W+1){
            int cnt = 0;
            if(G[i][j]=='#'){
                cout << '#';
            }else{
                for(int x: dx){
                    for(int y: dy){
                        if(x==0&&y==0) continue;
                        if(G[i+x][j+y] == '#') cnt++;
                    }
                }
                cout << cnt;
            }
        }
        cout << endl;
    }
    return 0;
}