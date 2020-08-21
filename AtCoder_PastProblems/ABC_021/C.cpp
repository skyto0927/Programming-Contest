#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

int a,b;
vector<vector<int>> G;
vector<int> dis;
vector<int> cnt;

const int MOD = 1e9+7;

void bfs(){
    queue<int> q;
    q.push(a);
    
    while(!q.empty()){
        int pos = q.front(); q.pop();

        for(auto next: G[pos]){
            if(dis[next] > dis[pos]+1){
                dis[next] = dis[pos]+1;
                cnt[next] = cnt[pos];
                q.push(next);
            }else if(dis[next] == dis[pos]+1){
                cnt[next] += cnt[pos];
                cnt[next] %= MOD;

                //q.push(next);
            }
        }
    }
}

int main() {
    int N; cin >> N;
    G.assign(N,vector<int>());
    cin >> a >> b;
    a--;
    b--;
    int M; cin >> M;
    REP(i,M){
        int x,y; cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dis.assign(N,INF);
    cnt.assign(N,0);
    dis[a] = 0;
    cnt[a] = 1;
    bfs();

    cout << cnt[b] << endl;

    return 0;
}