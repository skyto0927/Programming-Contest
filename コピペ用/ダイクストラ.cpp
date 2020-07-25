#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
template<typename T>

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


int main() {
    return 0;
}
///////////////////////////////////////////////////////

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