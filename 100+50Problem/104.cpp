#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


template<typename T>
vector<T> compress(vector<T> &C1, vector<T> &C2, int border){
    vector<T> vals;
    int N = (int)C1.size();
    REP(i,N){
        vals.push_back(C1[i]);
        //if(C1[i]!=border)  vals.push_back(C1[i]+1);
        
        vals.push_back(C2[i]);
        //if(C2[i]!=border)  vals.push_back(C2[i]+1);
    }

    vals.push_back(0);
    vals.push_back(border);

    sort(ALL(vals));
    vals.erase(unique(ALL(vals)), vals.end());

    REP(i,N){
        C1[i] = lower_bound(ALL(vals), C1[i]) - vals.begin();
        C2[i] = lower_bound(ALL(vals), C2[i]) - vals.begin();
    }

    return vals;
}

int w,h;
int W,H;
vector<vector<int>> G;

vector<int> dx{1,0,-1,0};
vector<int> dy{0,-1,0,1};

void bfs(queue<pair<int,int>> &q){
    while(!q.empty()){
        auto pos = q.front(); q.pop();


        REP(i,4){
            int nx = pos.first+dx[i], ny = pos.second+dy[i];
            if(nx<0 || nx>w-1 || ny<0 || ny>h-1)continue;
            if(G[nx][ny]>0) continue;
            G[nx][ny] = 1;

            q.push({nx,ny});
        }
    }
}

int main() {
    cin >> W >> H;
    int N; cin >> N;
    vector<int> X1(N),Y1(N), X2(N),Y2(N);
    REP(i,N){
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
    }

    vector<int> X = compress(X1,X2,W);
    vector<int> Y = compress(Y1,Y2,H);

    w = X.size();
    h = Y.size();

    G.assign(w, vector<int>(h,0));

    REP(i,N){
        G[X1[i]][Y1[i]] ++;
        G[X1[i]][Y2[i]] --;
        G[X2[i]][Y1[i]] --;
        G[X2[i]][Y2[i]] ++;
    }

    REP(x,w-1){
        REP(y,h){
            G[x+1][y] += G[x][y];
        }
    }
    REP(x,w){
        REP(y,h-1){
            G[x][y+1] += G[x][y];
        }
    }

    REP(i,w){//範囲外の設定
        G[i][h-1] = 1;
    }
    REP(i,h){
        G[w-1][i] = 1;
    }

    // REP(x,w){
    //     REP(y,h){
    //         if(G[x][y]>0){
    //             cout << '#';
    //         }else{
    //             cout << '.';
    //         }
    //     }
    //     cout << endl;
    // }

    int ans = 0;
    REP(x,w){
        REP(y,h){
            if(G[x][y]==0){
                ans++;
                queue<pair<int,int>> q;
                q.push({x,y});
                G[x][y]=1;
                bfs(q);
            }
        }
    }

    cout << ans << endl;

    return 0;
}