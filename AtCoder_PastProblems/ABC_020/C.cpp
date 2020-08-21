#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

vector<int> dx{1,0,-1,0};
vector<int> dy{0,1,0,-1};
typedef pair<int,pair<int,int>> P;

int main() {
    int H,W,T; cin >> H >> W >> T;
    vector<vector<char>> G(H+2, vector<char>(W+2,'x'));
    pair<int,int> start, goal;
    REP(i,H){
        string s; cin >> s;
        REP(j,W){
            G[i+1][j+1] = s[j];
            if(s[j]=='S') start = {i+1,j+1};
            if(s[j]=='G') goal = {i+1,j+1};
        }
    }

    int ng = INF;
    int ok = 1;
    while(abs(ok-ng)>1){
        int mid = (ok+ng)/2;

        vector<vector<ll>> dp(H+2, vector<ll>(W+2,LINF));
        dp[start.first][start.second] = 0;
        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0,start});
        while(!q.empty()){
            auto pos = q.top(); q.pop();
            int x = pos.second.first;
            int y = pos.second.second;
            int d = pos.first;
            if(dp[x][y] < d)  continue;

            REP(i,4){
                if(G[x+dx[i]][y+dy[i]] == 'x') continue;
                else if(G[x+dx[i]][y+dy[i]] == '#'){
                    if(dp[x+dx[i]][y+dy[i]] > dp[x][y] + mid){
                        dp[x+dx[i]][y+dy[i]] = dp[x][y] + mid;
                        q.push({dp[x+dx[i]][y+dy[i]], {x+dx[i],y+dy[i]}});
                    }
                }else{
                    if(dp[x+dx[i]][y+dy[i]] > dp[x][y] + 1){
                        dp[x+dx[i]][y+dy[i]] = dp[x][y] + 1;
                        q.push({dp[x+dx[i]][y+dy[i]], {x+dx[i],y+dy[i]}});
                    }
                }
            }
        }
        //cout << mid << " " << dp[goal.first][goal.second] << endl;

        if(dp[goal.first][goal.second] <= T){//ここに条件をかく
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;


    return 0;
}