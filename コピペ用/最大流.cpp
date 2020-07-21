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

template<class T> struct Edge{
    int rev,from,to; // rev:逆向きの辺の番号
    T cap, original_cap;
    Edge(int r, int f, int t, T c):
        rev(r), from(f), to(t), cap(c), original_cap(c) {}
};

template<class T> struct Graph{
    vector<vector<Edge<T>>> G;
    Graph(int n=0): G(n){}
    vector<Edge<T>>& operator[](int i){
        return G[i];
    }
    const size_t size() const{
        return G.size();
    }

    Edge<T>& redge(Edge<T> e){// 逆向きの辺を返す
        return G[e.to][e.rev];// 自己ループはないと仮定（あれば G[e.to][e.rev + 1] とする必要がある）
    }

    void add_edge(int from, int to, T cap){// 有向辺を加える
        G[from].push_back(Edge<T>((int)G[to].size(), from, to, cap));
        G[to].push_back(Edge<T>((int)G[from].size() - 1, to, from, 0));
    }

};

/* FordFulkerson: Ford-Fulkersonのアルゴリズムで最大流を求める構造体
    max_flow(G,s,t)：sからtへのグラフGの最大流を求める
    副作用：G は最大流の残余ネットワークになる
    計算量: O(|f*||E|) (f*:最大流) (この最悪ケースになることはほぼ無い)
*/

template<class T> struct FordFulkerson{
    vector<int> used;

    FordFulkerson(){};
    T dfs(Graph<T>& G, int v, int t, T f){
        if(v==t) return f;
        used[v] = true;
        for(auto& e: G[v]){
            if(!used[e.to] && e.cap>0){
                T d = dfs(G, e.to, t, min(f, e.cap));
                if(d>0){
                    e.cap -= d;
                    G.redge(e).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T max_flow(Graph<T>& G, int s, int t){
        T flow = 0;
        while(1){
            used.assign(G.size(), 0);
            T f = dfs(G,s,t,INF);
            if(f==0) return flow;
            else flow += f;
        }
        return 0;
    }
};


/*
以下はメモ

int main() {
    int X, Y, E; //　左右の頂点数と辺の数
    cin >> X >> Y >> E;
    Graph<int> G(X + Y + 2);　//Gにはサイズを入れる
    for (int i = 0; i < X; i++) {  // ソース(0)から X(1~X) への辺
        G.add_edge(0, i + 1, 1);
    }
    for (int i = 0; i < E; i++) {  // X(1~X) から Y(X+1~X+Y) への辺
        int x, y;
        cin >> x >> y;
        G.add_edge(x + 1, y + X + 1, 1);
    }
    for (int i = 0; i < Y; i++) {  // Y(X+1~X+Y) からシンク(X+Y+1)への辺
        G.add_edge(i + X + 1, X + Y + 1, 1);
    }
 
    FordFulkerson<int> ff;
    cout << ff.max_flow(G, 0, X + Y + 1) << endl;
}

*/