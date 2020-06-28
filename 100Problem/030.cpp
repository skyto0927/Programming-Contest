#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int H,W;
int N;

vector<int> dx{1,0,-1,0};
vector<int> dy{0,1,0,-1};

int main() {
    cin >> H >> W >> N;
    vector<vector<char>> G(H+2, vector<char>(W+2, 'X'));

    vector<pair<int,int>> factory(N+1);

    REP(i,H){
        string S;
        cin >> S;

        REP(j,W){
            G[i+1][j+1] = S[j];

            if(G[i+1][j+1] == 'S'){
                factory[0] = make_pair(i+1, j+1);
                G[i+1][j+1] = '.';
            }
            REP(k,N){
                if(G[i+1][j+1] == '0' + (k+1)){
                    factory[k+1] = make_pair(i+1, j+1);
                    G[i+1][j+1] = '.';
                }
                
            }
        }
    }

    int sum=0;

    REP(k,N){
        int counter = 0;

        vector<vector<int>> dist(H+2, vector<int>(W+2, -1));

        //start...factory[k], goal...factory[k+1]
        queue<pair<int,int>> q;
        q.push(factory[k]);
        dist[factory[k].first][factory[k].second] = 0;
        

        while(!q.empty()){
            auto v = q.front();
            q.pop();
            if (v == factory[k+1]){
                sum += dist[v.first][v.second];
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

    }
    cout << sum << endl;
    
    return 0;
}
