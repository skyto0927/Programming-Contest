#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

using Graph = vector<vector<int>>;

Graph G;

int n;


int main() {
    cin >> n;
    G.assign(n, vector<int>());
    REP(i,n){
        int u;
        cin >> u;
        u--;
        int k;
        cin >> k;
        REP(j,k){
            int v;
            cin >> v;
            v--;
            G[u].push_back(v);
        }
    }
    vector<int> dist(n, -1);
    queue<int> que;

    dist[0] = 0;
    que.push(0);

    while(!que.empty()){
        int v = que.front();
        que.pop();

        for(int next: G[v]){
            if(dist[next]!=-1) continue;

            dist[next] = dist[v] + 1;
            que.push(next);
        }
    }
    REP(i,n){
        cout << i+1 << " " << dist[i] << endl;
    }
    return 0;
}
