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
    int s,t;
    double cost;
    bool operator<(const Edge &o) const{
        return cost < o.cost;
    }
};

struct Graph{
    int n;
    vector<Edge> es;

    double kruskal(){
        sort(ALL(es));

        UnionFind uf(n);
        double min_cost = 0;
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
    while(1){
        int n; cin >> n;
        if (n==0){
            return 0;
        }

        vector<vector<double>> inputs(n, vector<double>(4));
        REP(i,n){
            double x,y,z,r; cin >> x >> y >> z >> r;
            inputs[i] = {x,y,z,r};
        }

        Graph g;
        g.n = n;

        REP(i,n-1){
            FOR(j,i+1,n){
                double l;
                l = sqrt( pow(inputs[i][0]-inputs[j][0], 2)+pow(inputs[i][1]-inputs[j][1], 2)+pow(inputs[i][2]-inputs[j][2], 2));
                if (l <= inputs[i][3]+inputs[j][3]){
                    g.es.push_back({i,j,0.0});
                }else{
                    g.es.push_back({i,j,l-inputs[i][3]-inputs[j][3]});
                }
            }
        }

        cout << fixed << setprecision(3) << g.kruskal() << endl;
    }
}