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
    ll to;
};
using Graph = vector<vector<Edge>>;

struct LCA{
    vector<vector<int>> parent;
    vector<int> dist;
    LCA(const Graph &G, int root=0){
        init(G,root);
    }

    void init(const Graph &G, int root=0){
        int V = G.size();
        int K = 1;
        while((1<<K) < V) K++;
        parent.assign(K, vector<int>(V,-1));
        dist.assign(V,-1);
        dfs(G, root, -1, 0);
        REP(k,K-1){
            REP(v,V){
                if(parent[k][v]<0){
                    parent[k+1][v] = -1;
                }else{
                    parent[k+1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }
    void dfs(const Graph &G, int v, int p, int d){
        parent[0][v] = p;
        dist[v] = d;
        for(auto e: G[v]){
            if(e.to != p) dfs(G, e.to, v, d+1);
        }
    }

    int query(int u, int v){
        if(dist[u] < dist[v]) swap(u, v);
        int K = parent.size();

        REP(k,K){
            if((dist[u]-dist[v])>>k & 1){
                u = parent[k][u];
            }
        }

        if(u==v) return u;
        REPR(k, K-1){
            if(parent[k][u] != parent[k][v]){
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    int get_dist(int u, int v){
        return dist[u] + dist[v] - 2*dist[query(u,v)];
    }

    bool is_on_path(int u, int v, int a){
        return get_dist(u,a) + get_dist(a,v) == get_dist(u,v);
    }
};

int main() {
    int N; cin >> N;
    Graph G(N);
    REP(i,N-1){
        int x,y; cin >> x >> y;
        x--;
        y--;
        G[x].push_back({y});
        G[y].push_back({x});
    }

    LCA lca(G, 0);
    int Q; cin >> Q;
    REP(i,Q){
        int a, b; cin >> a >> b;
        a--; b--;
        cout << lca.get_dist(a,b) + 1 << endl;
    }
    return 0;
}