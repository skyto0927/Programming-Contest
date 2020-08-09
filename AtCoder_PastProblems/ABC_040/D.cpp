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
    int s,t,cost;
    bool operator<(const Edge &o) const{
        return cost > o.cost;
    }
};
struct Queries{
    int v,w,id;
    bool operator<(const Queries &o) const{
        return w > o.w;
    }
};


struct UnionFind{
    vector<int> data;
    //data[i] = -x ... iが根であり、サイズがx
    //data[i] = x ... iの親がx

    //最初は全員根
    UnionFind(int size): data(size,-1){}

    bool union_set(int x, int y){//サイズがx>yになるようにしてから、xにyをつなげる
        x=root(x);
        y=root(y);
        if(x != y){
            if(data[y] < data[x]) swap(x,y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool find_set(int x, int y){//ルートが一致するかどうかを返す
        return root(x) == root(y);
    }
    int root(int x){//根を見つける。ついでに深さ2にしちゃう
        return data[x]<0 ? x : data[x]=root(data[x]);
    }
    int size(int x){
        return -data[root(x)];
    }
};

int main() {
    int N,M; cin >> N >> M;
    vector<Edge> edges;
    REP(i,M){
        int a,b,y; cin >> a >> b >> y;
        edges.push_back({a-1,b-1,y});
    }
    sort(ALL(edges));

    int Q; cin >> Q;
    vector<Queries> q;
    REP(i,Q){
        int v,w; cin >> v >> w;
        q.push_back({v-1,w,i});
    }
    vector<int> ans(Q);
    sort(ALL(q));
    UnionFind uf(N);

    int id = 0;
    REP(i,Q){
        while(edges[id].cost > q[i].w){
            uf.union_set(edges[id].s, edges[id].t);
            id++;
        }
        ans[q[i].id] = uf.size(q[i].v);
    }

    REP(i,Q) cout << ans[i] << endl;

    return 0;
}