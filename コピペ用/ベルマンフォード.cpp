#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

struct Edge{
    ll from, to, cost;
};

using Edges = vector<Edge>;

bool bellman_ford(Edges &Es, int V, int s, vector<ll>& dis){
    dis.resize(V,LINF);
    dis[s] = 0;
    int cnt = 0;
    while(cnt < V){
        bool end = true;
        for(auto e: Es){
            if(dis[e.from] != LINF && dis[e.from]+e.cost < dis[e.to]){
                dis[e.to] = dis[e.from] + e.cost;
                end = false;
            }
        }
        if(end) break;
        cnt++;
    }
    return (cnt==V);
}