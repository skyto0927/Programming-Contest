#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

typedef pair<int,int> P;

vector<int> dx{1,0,-1,0};
vector<int> dy{0,1,0,-1};

int main() {
    int R,C; cin >> R >> C;
    vector<vector<char>> G(R, vector<char>(C,'#'));
    P s,g;
    cin >> s.first >> s.second;
    cin >> g.first >> g.second;
    s.first--;
    s.second--;
    g.first--;
    g.second--;
    REP(i,R){
        string s; cin >> s;
        REP(j,C){
            G[i][j] = s[j];
        }
    }
    vector<vector<int>> dist(R, vector<int>(C,-1));
    dist[s.first][s.second] = 0;

    queue<P> q;
    q.push(s);

    while(!q.empty()){
        auto pos = q.front(); q.pop();

        int x = pos.first;
        int y = pos.second;
        REP(i,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(G[nx][ny]=='#') continue;

            if(dist[nx][ny] == -1){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
    cout << dist[g.first][g.second] << endl;
    return 0;
}