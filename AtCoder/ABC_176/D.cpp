#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

vector<int> d{-2,-1,0,1,2};

vector<int> dx{1,0,-1,0};
vector<int> dy{0,1,0,-1};

vector<int> dx2{1,1,-1,-1};
vector<int> dy2{1,-1,-1,1};

int main() {
    int H,W; cin >> H >> W;
    pair<int,int> start, goal;
    cin >> start.first >> start.second;
    start.first++;
    start.second++;
    cin >> goal.first >> goal.second;
    goal.first++;
    goal.second++;

    vector<vector<char>> G(H+4, vector<char>(W+4,'#'));
    vector<vector<int>> dp(H+4, vector<int>(W+4,INF));
    REP(i,H){
        string s; cin >> s;
        REP(j,W){
            G[i+2][j+2] = s[j];
        }
    }

    deque<pair<int, pair<int,int>>> q;
    q.push_front({0, start});
    dp[start.first][start.second] = 0;

    while(!q.empty()){
    
        auto pos = q.front(); q.pop_front();
        int x = pos.second.first;
        int y = pos.second.second;
        int t = pos.first;
        //cout << x-1 << " " << y-1 << endl;


        if(t > dp[x][y]) continue;

        REP(i,4){//隣接
            if(G[x+dx[i]][y+dy[i]] == '.'){
                if(dp[x+dx[i]][y+dy[i]] > dp[x][y]){
                    dp[x+dx[i]][y+dy[i]] = dp[x][y];
                    q.push_front({dp[x+dx[i]][y+dy[i]], {x+dx[i],y+dy[i]}});
                }
            }
        }

        REP(i,4){//斜め
            if(G[x+dx2[i]][y+dy2[i]] == '.'){
                if(dp[x+dx2[i]][y+dy2[i]] > 1+dp[x][y]){
                    dp[x+dx2[i]][y+dy2[i]] = 1+dp[x][y];
                    q.push_back({dp[x+dx2[i]][y+dy2[i]], {x+dx2[i],y+dy2[i]}});
                }
            }
        }

        REP(i,5){
            REP(j,5){
                if(abs(d[i])!=2 && abs(d[j])!=2) continue;

                if(G[x+d[i]][y+d[j]] == '.'){
                    if(dp[x+d[i]][y+d[j]] > 1+dp[x][y]){
                        dp[x+d[i]][y+d[j]] = 1+dp[x][y];
                        q.push_back({dp[x+d[i]][y+d[j]], {x+d[i],y+d[j]}});
                    }
                }    
            }
        }
    }
    int ans = dp[goal.first][goal.second];
    cout << (ans==INF?-1:ans) << endl;

    return 0;
}