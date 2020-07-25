#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

using P = pair<ll, int>;
struct Edge{
    ll to,cost;
};

template<class T> void dijkstra(vector<vector<Edge>>& G, int s, vector<T>& dis){
    int N = G.size();
    priority_queue<P, vector<P>, greater<P>> q;
    dis[s] = 0;
    q.push({dis[s],s});

    while(!q.empty()){
        auto pos = q.top(); q.pop();

        int v = pos.second;
        if(dis[v] < pos.first) continue;
        for(auto next: G[v]){
            if(next.to == v)continue; //無限ループの回避
            if(dis[next.to] > dis[v]+next.cost){
                dis[next.to] = dis[v]+next.cost;
                q.push({dis[next.to], next.to});
            }
        }
    }
}

int main() {
    int N; cin >> N;
    vector<vector<Edge>> G(N);
    REP(i,N-1){
        ll a,b,c; cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    int Q,K; cin >> Q >> K;
    K--;
    vector<ll> dist(N,1e15);
    dijkstra(G,K,dist);

    REP(i,Q){
        int x,y; cin >> x >> y;
        x--;
        y--;
        cout << dist[x]+dist[y] << endl;
    }

    return 0;
}