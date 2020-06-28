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

vector<vector<int>> G;
int w,h;

void dfs(vector<vector<int>> &G, int x, int y){
    if (G[y][x] == 1){
        G[y][x] = 0;

        REP(i,3){
            REP(j,3){
                int next_x = x+dx[i];
                int next_y = y+dy[j];
                if (i==1 && j==1)continue;
                if (0<=next_x && next_x<w && 0<=next_y && next_y<h){
                    dfs(G, next_x, next_y);
                }
            }
        }
    }
}

int main() {
    while(1){
        
        cin >> w >> h;
        if(w==0 && h==0) break;
        G.assign(h, vector<int>(w, 0));
        REP(i,h){
            REP(j,w){
                cin >> G[i][j];
            }
        }

        int count = 0;
        REP(i,h){
            REP(j,w){
                if (G[i][j] == 1){
                    count ++;
                    dfs(G, j, i);//G,w,h
                
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
