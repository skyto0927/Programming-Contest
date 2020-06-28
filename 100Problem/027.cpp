#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


using Graph = vector<vector<int>>;
Graph G;
int m,n;

vector<int> dx{1,0,-1,0};
vector<int> dy{0,1,0,-1};

int count_ice;
int max_ice;

void dfs(int x, int y){
    if(G[y][x] == 1){
        G[y][x] = 0;
        count_ice++;
        REP(i,4){
            int next_x = x+dx[i];
            int next_y = y+dy[i];

            if(0<=next_x && next_x<m && 0<=next_y && next_y<n){
                dfs(next_x, next_y);
            }
        }

        max_ice = max(max_ice, count_ice);
        count_ice--;
        G[y][x] = 1;
    }
}
    

int main() {
    cin >> m;//east
    cin >> n;//north

    G.assign(n, vector<int>(m));
    REP(i,n){
        REP(j,m){
            cin >> G[i][j];
        }
    }

    max_ice = 0;
    REP(i,n){
        REP(j,m){
            count_ice = 0;
            dfs(j, i);
        }
    }

    cout << max_ice << endl;
    return 0;
}
