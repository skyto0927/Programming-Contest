#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int w,h;

int main() {
    while(1){
        cin >> w >> h;

        if (w==0 && h==0){
            return 0;
        }

        vector<vector<vector<pair<int,int>>>> G(h, vector<vector<pair<int,int>>>(w));

        int wall;
        REP(i,2*h-1){
            if(i%2==0){//横の壁
                REP(j,w-1){
                    cin >> wall;
                    if (wall == 0){
                        G[i/2][j].push_back(make_pair(i/2,j+1));
                        G[i/2][j+1].push_back(make_pair(i/2,j));
                    }
                }
            }else{//縦の壁
                REP(j,w){
                    cin >> wall;
                    if (wall == 0){
                        G[i/2][j].push_back(make_pair(i/2+1,j));
                        G[i/2+1][j].push_back(make_pair(i/2,j));
                    }
                }
            }
        }

        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        vector<vector<int>> dist(h,vector<int>(w,-1));
        dist[0][0] = 1;
        bool finished = false;
        while(!q.empty()){
            auto v = q.front();
            q.pop();

            if (v.first == h-1 && v.second == w-1){
                cout << dist[v.first][v.second] << endl;
                finished = true;
                break;
            }

            for (auto next: G[v.first][v.second]){
                if(dist[next.first][next.second] == -1){
                    dist[next.first][next.second] = dist[v.first][v.second]+1;
                    q.push(next);
                }
            }

        }
        if (!finished){
            cout << 0 << endl;
        }

    }

    return 0;
}
