#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

vector<int> start(2);
vector<int> goal(2);
int R,C;


vector<int> dx{1,0,-1,0};
vector<int> dy{0,1,0,-1};

int main() {
    cin >> R >> C;
    cin >> start[0] >> start[1];
    start[0]--;
    start[1]--;
    cin >> goal[0] >> goal[1];//y,x
    goal[0]--;
    goal[1]--;
    vector<vector<char>> G(R, vector<char>(C, '.'));
    vector<vector<int>> dist(R, vector<int>(C, -1));
    REP(i,R){
        string S;
        cin >> S;
        REP(j,C){
            G[i][j] = S[j];
        }
    }

    queue<vector<int>> q;

    dist[start[0]][start[1]]=0;
    q.push(start);
    vector<int> v(2);

    while(!q.empty()){

        v = q.front();
        q.pop();

        if (v[0] == goal[0] && v[1] == goal[1]){
            cout << dist[v[0]][v[1]]<< endl;
            return 0;
        }
        REP(i,4){
            int next_x = v[1]+dx[i], next_y = v[0]+dy[i];
            if(G[next_y][next_x] == '.' && dist[next_y][next_x] == -1){
                q.push({next_y, next_x});
                dist[next_y][next_x] = dist[v[0]][v[1]] + 1;        
            }
        }
    }

    return 0;
}
