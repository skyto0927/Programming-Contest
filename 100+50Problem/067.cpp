#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

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

struct Edge{
    int s,t,cost;
    bool operator<(const Edge &o) const{
        return cost < o.cost;
    }
};

struct Graph{
    int n;
    vector<Edge> es;

    int kruskal(){
        sort(ALL(es));

        UnionFind uf(n);
        int min_cost = 0;
        REP(i,es.size()){
            Edge& e = es[i];
            if(!uf.find_set(e.s, e.t)){//辺を追加しても閉路ができなければ採用
                min_cost += e.cost;
                uf.union_set(e.s, e.t);
            }
        }

        return min_cost;
    }
};

int main() {

    int N;
    cin >> N;
    vector<pair<int,int>> coord_x;
    vector<pair<int,int>> coord_y;
    REP(i,N){
        int id, x, y;
        cin >> x >> y;
        id = i;
        coord_x.push_back(make_pair(x,id));
        coord_y.push_back(make_pair(y,id));
    }
    sort(ALL(coord_x));
    sort(ALL(coord_y));

    Graph g;
    g.n = 2*N-2;

    REP(i,N-1){
        Edge ex;
        ex.s = coord_x[i].second;
        ex.t = coord_x[i+1].second;
        ex.cost = abs(coord_x[i].first - coord_x[i+1].first);
        g.es.push_back(ex);
        Edge ey;
        ey.s = coord_y[i].second;
        ey.t = coord_y[i+1].second;
        ey.cost = abs(coord_y[i].first - coord_y[i+1].first);
        g.es.push_back(ey);
    }

    sort(ALL(g.es));

    cout << g.kruskal() << endl;


    return 0;
}