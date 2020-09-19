#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


struct Edge{
    ll from, to, cost;
};

using Edges = vector<Edge>;
vector<bool> negative;


void bellman_ford(Edges &Es, int V, int s, vector<ll>& dis){
    dis.resize(V,LINF);
    dis[s] = 0;
    int cnt = 0;

    while(cnt < V){
        for(auto e: Es){

            if(dis[e.from] != LINF && dis[e.from]+e.cost < dis[e.to]){
                dis[e.to] = dis[e.from] + e.cost;
            }
        }
        cnt++;
    }

    negative.resize(V,false);
    cnt = 0;

    while(cnt < V){
        for(auto e: Es){

            if(dis[e.to] != LINF && dis[e.from]+e.cost < dis[e.to]){
                dis[e.to] = dis[e.from] + e.cost;
                negative[e.to] = true;
            }
            if(negative[e.from]) negative[e.to] = true;
        }
        cnt++;
    }
    return;
}

int main() {
    int N,M,P; cin >> N >> M >> P;

    vector<Edge> Es(M);

    REP(i,M){
        int a,b,c; cin >> a >> b >> c;
        a--;
        b--;
        c -= P;
        Es[i] = {a,b,-c};
    }

    vector<ll> dis(N,LINF);

    bellman_ford(Es, N, 0, dis);

    if(!negative[N-1]){
        cout << max(-dis[N-1],0ll) << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}