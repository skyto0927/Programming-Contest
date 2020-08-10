#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

using P = pair<ll, int>;
struct Edge{
    ll to,cost;
};

template<class T> void dijkstra(vector<vector<Edge>>& G, int s, vector<T>& dis){
    int N = G.size();
    dis.resize(N, LINF);
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
    ll N,M,T; cin >> N >> M >> T;
    vector<ll> A(N);
    REP(i,N) cin >> A[i];
    vector<vector<Edge>> G1(N);
    vector<vector<Edge>> G2(N);
    REP(i,M){
        int a,b,c; cin >> a >> b >> c;
        a--;
        b--;
        G1[a].push_back({b,c});
        G2[b].push_back({a,c});
    }
    vector<ll> dis1;
    dijkstra(G1,0,dis1);

    vector<ll> dis2;
    dijkstra(G2,0,dis2);

    ll ans = 0;
    REP(i,N){
        if(dis1[i]+dis2[i] > T) continue;
        else{
            ans = max(ans, (T-dis1[i]-dis2[i]) * A[i]);
        }
    }
    cout << ans << endl;

    return 0;
}