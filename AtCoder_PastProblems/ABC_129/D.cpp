#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


vector<vector<int>> G;
vector<vector<int>> yoko;
vector<vector<int>> tate;

int solve_yoko(int i, int j, int n){
    if(yoko[i][j] != -1) return yoko[i][j];
    
    if(G[i+1][j] == '#'){
        yoko[i][j] = n;
        return n;
    }else{
        yoko[i][j] = solve_yoko(i+1,j,n+1);
        return yoko[i][j];
    }
}

int solve_tate(int i, int j, int n){
    if(tate[i][j] != -1) return tate[i][j];
    
    if(G[i][j+1] == '#'){
        tate[i][j] = n;
        return n;
    }else{
        tate[i][j] = solve_tate(i,j+1,n+1);
        return tate[i][j];
    }
}

int main() {
    int H,W; cin >> H >> W;
    G.assign(H+2, vector<int>(W+2,'#'));
    REP(i,H){
        string s; cin >> s;
        REP(j,W){
            G[i+1][j+1] = s[j];
        }
    }

    yoko.assign(H+2, vector<int>(W+2,-1));
    tate.assign(H+2, vector<int>(W+2,-1));

    int ans = 0;
    REP(i,H+2){
        REP(j,W+2){
            if(G[i][j] == '.'){
                ans = max(ans, solve_yoko(i,j,1) + solve_tate(i,j,1) - 1);              
            }
        }
    }
    cout << ans << endl;
    return 0;
}