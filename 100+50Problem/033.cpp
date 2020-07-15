#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int H,W;
int walls;
vector<int> dx{1,0,-1,0};
vector<int> dy{0,1,0,-1};


int main() {
    cin >> H >> W;

    walls = 0;

    vector<vector<char>> G(H+2, vector<char>(W+2, '#'));

    REP(i,H){
        string S;
        cin >> S;
        REP(j,W){
            G[i+1][j+1] = S[j];
            if(S[j] == '#') walls++;
        }
    }

    queue<pair<int,int>> q;
    q.push(make_pair(1,1));

    vector<vector<int>> dist(H+2, vector<int>(W+2, -1));

    dist[1][1] = 1;
    
    int d = -1;

    while(!q.empty()){
        auto v = q.front();
        q.pop();
        if (v == make_pair(H,W)){
            d = dist[v.first][v.second];
            break;
        }
        REP(i,4){
            pair<int,int> next{v.first+dy[i], v.second+dx[i]};
            if (G[next.first][next.second] == '.' && dist[next.first][next.second] == -1){
                dist[next.first][next.second] = dist[v.first][v.second]+1;
                q.push(next);
            }
        }

    }

    if (d==-1){
        cout << -1 << endl;
    }else{
        cout << W*H - walls - d << endl;
    }
    return 0;
}
