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
    dis.resize(N, INF);
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
    int K; cin >> K;
    vector<vector<Edge>> G(K);

    REP(i,K){
        G[i].push_back({(i+1)%K,1});
        G[i].push_back({(i*10)%K,0});
    }
    vector<ll> dis;
    dijkstra(G,1,dis);

    cout << dis[0]+1 << endl;
    return 0;
}